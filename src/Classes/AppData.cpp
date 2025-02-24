//
// Created by Surfer Boy on 11/12/2024.
//
#include "../Standards//FileStorageDevice.hpp"
#include "AppData.hpp"


AppData::AppData() {
    this->storageDirectory = "/app/data";
    this->keyFileName = "";
    this->referenceFileName = "";
    this->valueFileName = "";
    this->storageDevice = new FileStorageDevice(this->storageDirectory);
    this->storage = new Storage(this->storageDevice);
}
std::string AppData::getStorageDirectory() {
    return this->storageDirectory;
}
std::string AppData::getKeyFileName() {
    return this->keyFileName;
}
std::string AppData::getReferenceFileName() {
    return this->referenceFileName;
}

std::string AppData::getValueFileName() {
    return this->valueFileName;
}
StorageDevice* AppData::getStorageDevice() {
    return this->storageDevice;
}
Storage* AppData::getStorage() {
    return this->storage;
}