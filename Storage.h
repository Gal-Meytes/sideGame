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
        Storage();
        virtual int add(StoringType Type, Storable* storable);
        virtual void* retrieve(StoringType Type, Storable* storable);
        virtual int update(StoringType Type, Storable* storable);
};


#endif //PROJECT_STORAGEDEVICE_H
