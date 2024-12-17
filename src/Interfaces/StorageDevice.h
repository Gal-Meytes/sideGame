//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef STORAGEDEVICE_H
#define STORAGEDEVICE_H
#include "iostream"

class StorageDevice {
public:
    ~StorageDevice() = default;
     StorageDevice() = default;
    virtual std::string* find(std::string key) = 0;
    virtual int add(std::string key, std::string value, std::string** error) = 0;
    virtual int update(std::string key, std::string value, std::string** error) = 0;
    virtual off_t getKey(off_t offset, std::string* buffer) = 0;
};


#endif //STORAGEDEVICE_H
