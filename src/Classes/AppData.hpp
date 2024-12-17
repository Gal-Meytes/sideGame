//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_APPDATA_HPP
#define MY_PROJECT_APPDATA_HPP
#include "iostream"
#include "../Interfaces/StorageDevice.h"
#include "Storage.h"

class AppData {
private:
    std::string storageDirectory;
    std::string keyFileName;
    std::string referenceFileName;
    std::string valueFileName;
    StorageDevice* storageDevice;
    Storage* storage;
public:
    explicit AppData();
    std::string getStorageDirectory();
    std::string getKeyFileName();
    std::string getReferenceFileName();
    std::string getValueFileName();
    StorageDevice* getStorageDevice();
    Storage* getStorage();
};


#endif //MY_PROJECT_APPDATA_HPP
