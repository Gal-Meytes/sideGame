//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_ISTORAGEDEVICEFACTORY_HPP
#define MY_PROJECT_ISTORAGEDEVICEFACTORY_HPP
#include "../../Interfaces/StorageDevice.h"

class IStorageDeviceFactory {
public:
    virtual StorageDevice* fabricateStorageDevice() = 0;
};


#endif //MY_PROJECT_ISTORAGEDEVICEFACTORY_HPP
