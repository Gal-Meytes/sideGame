//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef STORAGEDEVICE_H
#define STORAGEDEVICE_H
#include "LibraryDependencies.h"
#include <fstream>

class StorageDevice {
protected:
    int iteratorPos = 0;
public:
    ~StorageDevice() = default;
     StorageDevice() = default;
    virtual std::string* find(std::string key) = 0;
    virtual int add(std::string key, std::string value, std::string** error) = 0;
    virtual int update(std::string key, std::string value, std::string** error) = 0;
    virtual std::string begin() = 0;
    virtual bool hitEOF() = 0;
    virtual std::string next() = 0;
};


#endif //STORAGEDEVICE_H
