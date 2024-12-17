//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_FILESTORAGEDEVICEFACTORY_HPP
#define MY_PROJECT_FILESTORAGEDEVICEFACTORY_HPP
#include "IStorageDeviceFactory.hpp"
#include "AppData.hpp"
class FileStorageDeviceFactory : public IStorageDeviceFactory {
public:
    FileStorageDeviceFactory(AppData* appdata);
    virtual StorageDevice * storageDevice() override;
};


#endif //MY_PROJECT_FILESTORAGEDEVICEFACTORY_HPP
