//
// Created by Surfer Boy on 11/12/2024.
//

#include "FileStorageDeviceFactory.hpp"
FileStorageDeviceFactory::FileStorageDeviceFactory(std::string *folderDir) {
    this->folderDir = folderDir;
}

StorageDevice *FileStorageDeviceFactory::fabricateStorageDevice() {
    return new FileStorageDevice(*this->folderDir);
}