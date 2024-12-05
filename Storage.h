//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H
#include "user.h"
#include "StorageDevice.h"
#include "Storable.h"
enum StoringType {
    UserType
};

class Storage {
    protected:
    StorageDevice device;
    public:
        Storage(std::string directory);
        virtual int add(StoringType Type, Storable* item);
        virtual void* retrieve(StoringType Type, Storable* item);
        virtual int update(StoringType Type, Storable* item);
};


#endif //PROJECT_STORAGEDEVICE_H
