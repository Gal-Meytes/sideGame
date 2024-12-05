//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef STORAGEDEVICE_H
#define STORAGEDEVICE_H
#include "LibraryDependencies.h"

class StorageDevice {
public:
    StorageDevice();
    std::string* find(std::string key);
    int add(std::string key, std::string value, std::string** error);
    int update(std::string key, std::string value, std::string** error);
};


#endif //STORAGEDEVICE_H
