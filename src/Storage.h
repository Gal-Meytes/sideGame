//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H
#include "User.h"
#include "StorageDevice.h"
#include "Storable.h"
enum StoringType {
    UserType,
    Undefined
};

class Storage {
private:
    StorageDevice* device;
public:
    explicit Storage(StorageDevice* device);
    virtual int add(StoringType Type, Storable* item);
    virtual std::string* retrieve(StoringType Type, Storable* item);
    virtual int update(StoringType Type, Storable* item);
    virtual std::string* getKey(StoringType storingType, off_t index, off_t* nextIndex);

private:
    std::string getKey(StoringType storingType, Storable *item);
    std::string storingTypeToString(StoringType storingType);
//protected:
//    void setDevice(StorageDevice device);
    StoringType storingTypeOfString(std::string str);
    std::string getIdentityFromKey(std::string key);
};


#endif //PROJECT_STORAGEDEVICE_H