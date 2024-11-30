//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H
#include "user.h"
#include "StorageDevice.h"
enum StoringType {
    UserType
};

class Storage {
    protected:
    StorageDevice device;
    public:
        Storage();
        virtual int add(StoringType Type, void* item);
        virtual void* retrieve(StoringType Type, int identifier);
        virtual int update(StoringType Type, void* identifier);
};


#endif //PROJECT_STORAGEDEVICE_H
