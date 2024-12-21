//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_FILESTORAGEDEVICEFACTORY_HPP
#define MY_PROJECT_FILESTORAGEDEVICEFACTORY_HPP
#include "Abstract Factories/IStorageDeviceFactory.hpp"
#include "../Standards/FileStorageDevice.hpp"
class FileStorageDeviceFactory : public IStorageDeviceFactory {
private:
    std::string* folderDir;
public:
    FileStorageDeviceFactory(std::string * folderDir);
    virtual StorageDevice * fabricateStorageDevice() override;
};


#endif //MY_PROJECT_FILESTORAGEDEVICEFACTORY_HPP
