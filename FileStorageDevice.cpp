//
// Created by Surfer Boy on 30/11/2024.
//
#include "LibraryDependencies.h"
#include "StorageDevice.h"
#define MAGIC_STRING "keys"
#define MAGIC_STRING_2 "offsets"
#define MAGIC_STRING_3 "values"
/***
 * FileStorageDevice handles storing and retrieving key-value data using a filesystem-based approach.
 * Data is stored across three files:
 * - KeyFile: Contains keys as strings.
 * - OffsetFile: Contains offsets (as `off_t`) corresponding to value locations in ValueFile.
 * - ValueFile: Contains values as strings.
 *
 * Retrieval involves:
 * 1. Locating the key in KeyFile.
 * 2. Finding its index and using that to get the corresponding offset from OffsetFile.
 * 3. Using the offset to fetch the value from ValueFile.
 */
class FileStorageDevice : StorageDevice {
private:
    int keyFd;
    int offsetFd;
    int valueFd;
public:
    FileStorageDevice(std::string directory) {
        std::string first_subdir = (directory + std::string(MAGIC_STRING));
        std::string second_subdir = (directory + std::string(MAGIC_STRING_2));
        std::string third_subdir = (directory + std::string(MAGIC_STRING_3));

        this->keyFd = open(first_subdir.c_str(), O_CREAT | O_RDWR, 0777);
        this->offsetFd = open(second_subdir.c_str(), O_CREAT | O_RDWR, 0777);
        this->valueFd = open(third_subdir.c_str(), O_CREAT | O_RDWR, 0777);

    }

    std::string* find(std::string key) {
        long long index = findKeyIndex(key);
        //unsigned type might be a problem
        if (index == -1) {
            return NULL;
        }
        off_t offset = getOffsetByIndex(index);
        lseek(valueFd, offset, SEEK_SET);
        return nextStringInFile(valueFd, NULL);
    }
    int add(std::string key, std::string value, std::string** error) {
        std::string* ignore;
        if (error == NULL)
            error = &ignore;
        if (findKeyIndex(key) != -1) {
            *error = new std::string ("Key " + key + " already exists");
            return 0;
        }
        appendToFile(keyFd, key);

        off_t offset = appendToFile(valueFd, value);
        long long index = findKeyIndex(key);
        changeOffsetFile(index, offset);
        return 1;
    }
    /*
     * currently just forgets last value, and points key to new value.
     * should improve on it.
     */
    int update(std::string key, std::string value, std::string** error) {
        long long index = findKeyIndex(key);
        if (index == -1) {
            *error = new std::string ("Key " + key + " Not Found");
            return 0;
        }
        off_t valueOffset = appendToFile(valueFd, value);
        changeOffsetFile(index, valueOffset);
        return 1;
    }

private:
//    void addKey(std::string key) {
//        lseek(keyFd, 0, SEEK_END);
//        write(keyFd, key.c_str(), key.length() + 1);
//    }
    static off_t appendToFile(int fd, std::string value) {
        off_t offset = lseek(fd, 0, SEEK_END);
        write(fd, value.c_str(), value.length() + 1);
        return offset;
    }

    void changeOffsetFile(long long index, off_t offset) {
        off_t offsetWrite = sizeof (off_t) * index;
        lseek(offsetFd, offsetWrite,SEEK_SET);
        write(offsetFd, &offset, sizeof (offset));
    }

    off_t getOffsetByIndex(long long index) {
        size_t offsetRead = sizeof (off_t) * index;
        lseek(offsetFd, offsetRead, SEEK_SET);
        off_t returnVal;
        //future updates - should check for failure of read.
        read(offsetFd, &returnVal, sizeof (returnVal));
        return returnVal;
    }
    long long findKeyIndex(std::string key) {
        int error = ~EOF;
        long long i = 0;
        lseek(keyFd, 0, SEEK_SET);
        std::string* currString = nextStringInFile(keyFd, &error);

        while(currString != NULL) {
            if (!currString->compare(key))
                break;
            currString = nextStringInFile(keyFd, &error);
            i++;
        }
        if (currString == NULL)
            return -1;
        return i;
    }
    /*
     appends a null terminator if doesn't appear before return - worth to mention.
     error captures the reason the function unexpectedly failed, future updates -
     - should keep a logbook of the errors

     future updates - maybe use lseek seek_data
    */
     static std::string* nextStringInFile(int fd, int* error) {
        int numTries = 1000;
        int sleepMilliseconds = 200;
        std::vector<char> characters;
        char currChar;
        int ignored;

        if (error == NULL)
            error = &ignored;

        while (true) {
            int numRead = read(fd, &currChar, 1);
            if (numRead == 1) {
                characters.push_back(currChar);
                if (!currChar)
                    break;
            }
            if (numRead == 0)
                *error = EOF;

            //numRead == -1
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                if (!numTries) {
                    *error = errno;
                    break;
                }
                numTries--;
                usleep(sleepMilliseconds * 1000);
                continue;
            }
            if (errno == EINTR)
                continue;
            continue;
        }
        if (characters.empty())
            return NULL;
        if (characters.back() != '\0')
            characters.push_back('\0');
        return new std::string(characters.begin(), characters.end());
    }
};
