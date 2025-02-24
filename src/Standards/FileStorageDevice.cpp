//
// Created by Surfer Boy on 30/11/2024.
//


#define MAGIC_STRING "/keys.txt"
#define MAGIC_STRING_2 "/offsets.txt"
#define MAGIC_STRING_3 "/values.txt"
#define MAGIC_STRING_4 "/mutexFile"
#define IO_NUM_TRIES 1000;
#define IO_SLEEP_MILLISECONDS 200;

#include "../LibraryDependencies.h"
#include "FileStorageDevice.hpp"


FileStorageDevice::FileStorageDevice(std::string directory) {
    std::string first_subdir = (directory + std::string(MAGIC_STRING));
    std::string second_subdir = (directory + std::string(MAGIC_STRING_2));
    std::string third_subdir = (directory + std::string(MAGIC_STRING_3));
    std::string fourth_subdir = (directory + std::string(MAGIC_STRING_4));

    // Check if directories exist or create them
    if (mkdir(directory.c_str(), 0777) == -1 && errno != EEXIST) {
		printf("%s\n",directory.c_str());
		perror("mkdir failed");
        std::cerr << "something!!!" <<std::endl;
        // Handle directory creation failure
        std::cerr << "Error creating directory: " << directory << std::endl;
        return;
    }

    // Open files and check for errors
    this->keyFd = open(first_subdir.c_str(), O_CREAT | O_RDWR, 0644);
    if (this->keyFd == -1) {
        std::cerr << "Error opening key file: " << first_subdir << std::endl;
        return;
    }

    this->offsetFd = open(second_subdir.c_str(), O_CREAT | O_RDWR, 0644);
    if (this->offsetFd == -1) {
        std::cerr << "Error opening offset file: " << second_subdir << std::endl;
        close(this->keyFd);  // Clean up previously opened file
        return;
    }

    this->valueFd = open(third_subdir.c_str(), O_CREAT | O_RDWR, 0644);
    if (this->valueFd == -1) {
        std::cerr << "Error opening value file: " << third_subdir << std::endl;
        close(this->keyFd);
        close(this->offsetFd);  // Clean up previously opened files
        return;
    }
    this->lockFd = open(fourth_subdir.c_str(), O_CREAT | O_RDWR, 0644);
    if (this->lockFd == -1) {
        std::cerr << "Error opening lock file: " << third_subdir << std::endl;
        close(this->keyFd);
        close(this->offsetFd);  // Clean up previously opened files
        close(this->valueFd);
        return;
    }
}

FileStorageDevice::~FileStorageDevice() {
        if (this->keyFd != -1) {
            close(this->keyFd);
        }
        if (this->offsetFd != -1) {
            close(this->offsetFd);
        }
        if (this->valueFd != -1) {
            close(this->valueFd);
        }
        if (this->lockFd != -1) {
            close(this->lockFd);
        }
}

    std::string* FileStorageDevice::find(std::string key) {
        long long index = findKeyIndex(key);
        //unsigned type might be a problem
        if (index == -1) {
            return nullptr;
        }
        off_t offset = getOffsetByIndex(index);
        if (offset == -1) {
            return nullptr;
        }
        lseek(valueFd, offset, SEEK_SET);
        return nextStringInFile(valueFd, nullptr);
    }
    int FileStorageDevice::add(std::string key, std::string value, std::string** error) {
        // overide error pointer
        std::string* ignore;
        if (error == nullptr)
            error = &ignore;
        //check if key already exists in index
        if (findKeyIndex(key) != -1) {
            *error = new std::string ("Key " + key + " already exists");
            return 0;
        }

        off_t keyOffset = appendToFile(keyFd, key);
        if (keyOffset == -1)
            return 0;
        off_t offset = appendToFile(valueFd, value);
        if (offset == -1) {
            *error = new std::string ("Value got lost. Memory is corrupt");
            return 0;
        }
        long long index = findKeyIndex(key);
        if (index == -1) {
            *error = new std::string ("Key got lost. Memory is corrupt");
            return 0;
        }
        index = changeOffsetFile(index, offset);
        if (index == -1) {
            *error = new std::string ("Failed to connect key-value files. Memory is corrupt");
            return 0;
        }
        return 1;
    }
    /*
     * currently just forgets last value, and points key to new value.
     * should improve on it.
     */
    int FileStorageDevice::update(std::string key, std::string value, std::string** error) {
        long long index = findKeyIndex(key);
        if (index == -1) {
            *error = new std::string ("Key " + key + " Not Found");
            return 0;
        }
        off_t valueOffset = appendToFile(valueFd, value);
        if (valueOffset == -1) {
            *error = new std::string ("Key found but unable to update value");
            return 0;
        }
        changeOffsetFile(index, valueOffset);
        return 1;
    }
    off_t FileStorageDevice::getKey(off_t offset, std::string* buffer)  {
        lseek(keyFd, offset, SEEK_SET);
        int error;
        std::string* tmp = nextStringInFile(keyFd, &error);
        if (tmp == nullptr) {
            *buffer = std::string();
            return -1;
        }
        *buffer = *tmp;

        if (error == EOF)
            return -1;
        return lseek(keyFd, 0, SEEK_CUR);
    }

     off_t FileStorageDevice::appendToFile(int fd, std::string value) {
        ssize_t bytesWrote;
        int numTries = IO_NUM_TRIES;
        int sleepMilliseconds = IO_SLEEP_MILLISECONDS;

        off_t offset = lseek(fd, 0, SEEK_END);
        bytesWrote = write(fd, value.c_str(), value.length() + 1);
        if (bytesWrote == value.length() + 1)
            return offset;
        if (bytesWrote == -1) {
            return -1;
        }
        for (; numTries; numTries--) {
            if (ftruncate(fd, offset) != -1)
                return -1;
            usleep(sleepMilliseconds);
        }
        return -1;
    }

    int FileStorageDevice::changeOffsetFile(long long index, off_t offset) {
        off_t offsetWrite = sizeof (off_t) * index;
        //continue from here!!!!!
        lseek(offsetFd, offsetWrite,SEEK_SET);
        return (write(offsetFd, &offset, sizeof (offset)) == sizeof (offset) ? 1 : -1 );
    }

    off_t FileStorageDevice::getOffsetByIndex(long long index) {
        size_t offsetRead = sizeof (off_t) * index;
        lseek(offsetFd, offsetRead, SEEK_SET);
        off_t returnVal;
        //future updates - should check for failure of read.
        read(offsetFd, &returnVal, sizeof (returnVal));
        return returnVal;
    }
    long long FileStorageDevice::findKeyIndex(std::string key) {
        if (key.empty())
            return -1;
        int error = ~EOF;
        long long i = 0;
        lseek(keyFd, 0, SEEK_SET);
        std::string* currString = nextStringInFile(keyFd, &error);

        while(currString != nullptr) {
            if (strcmp(currString->c_str(),key.c_str()) == 0)
                break;
            currString = nextStringInFile(keyFd, &error);
            i++;
        }
        if (currString == nullptr)
            return -1;
        return i;
    }

bool FileStorageDevice::mutex() {
        int maxAttempts = IO_NUM_TRIES;
        int sleepTime = IO_SLEEP_MILLISECONDS;
        for (; maxAttempts > 0; maxAttempts--) {
            if (flock(this->lockFd, LOCK_EX | LOCK_NB) == -1)
                usleep(sleepTime);
            else
                return true;
        }
            return false;
}
bool FileStorageDevice::releaseMutex() {
    int maxAttempts = IO_NUM_TRIES;
    int sleepTime = IO_SLEEP_MILLISECONDS;
    for (; maxAttempts > 0; maxAttempts--) {
        if (flock(this->lockFd, LOCK_UN) == -1)
            usleep(sleepTime);
        else
            return true;
    }
    return false;
}
    /*
     appends a nullptr terminator if doesn't appear before return - worth to mention.
     error captures the reason the function unexpectedly failed, future updates -
     - should keep a logbook of the errors

     future updates - maybe use lseek seek_data
    */
    std::string* FileStorageDevice::nextStringInFile(int fd, int* error) {
        int numTries = IO_NUM_TRIES;
        int sleepMilliseconds = IO_SLEEP_MILLISECONDS;
        std::vector<char> characters;
        char currChar;
        int ignored;

        if (error == nullptr)
            error = &ignored;

        while (true) {
            int numRead = read(fd, &currChar, 1);
            if (numRead == 1) {
                characters.push_back(currChar);
                if (!currChar)
                    break;
            }
            if (numRead == 0) {
                *error = EOF;
                break;
            }

            //numRead == -1
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                if (!numTries) {
                    *error = errno;
                    break;
                }
                numTries--;
                usleep(sleepMilliseconds * 1000);
                continue;
            } if (errno == EINTR)
                continue;
        }
        if (characters.empty())
            return nullptr;
        if (characters.back() != '\0')
            characters.push_back('\0');
        return new std::string(characters.begin(), characters.end());
    }