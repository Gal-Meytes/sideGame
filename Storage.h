//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H
#include "User.h"
#include "StorageDevice.h"
#include "Storable.h"
enum StoringType {
    UserType
};

class Storage {
    private:
    StorageDevice* device;
    public:
        explicit Storage(StorageDevice* device);
        virtual int add(StoringType Type, Storable* item);
        virtual Storable* retrieve(StoringType storingType, const std::string& key);
        virtual int update(StoringType Type, Storable* item);
private:
    std::string getKey(StoringType storingType, Storable *item);
    std::string storingTypeToString(StoringType storingType);
//protected:
//    void setDevice(StorageDevice device);
};


#endif //PROJECT_STORAGEDEVICE_H
