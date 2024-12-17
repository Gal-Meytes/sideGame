//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_FILESTORAGEDEVICE_HPP
#define MY_PROJECT_FILESTORAGEDEVICE_HPP
#include "iostream"
#include "StorageDevice.h"
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
class FileStorageDevice : public StorageDevice {
private:
    int keyFd = -1;
    int offsetFd = -1;
    int valueFd = -1;

public:
    explicit FileStorageDevice(std::string directory);
    ~FileStorageDevice();
    std::string* find(std::string key) override;
    int add(std::string key, std::string value, std::string** error) override;
    int update(std::string key, std::string value, std::string** error) override;
    off_t getKey(off_t offset, std::string* buffer) override;

private:
    static off_t appendToFile(int fd, std::string value);
    int changeOffsetFile(long long index, off_t offset);
    off_t getOffsetByIndex(long long index);
    long long findKeyIndex(std::string key);
    static std::string* nextStringInFile(int fd, int* error);
};

#endif //MY_PROJECT_FILESTORAGEDEVICE_HPP