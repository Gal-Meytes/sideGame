//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H

#include "User.h"
#include "StorageDevice.h"
#include "Storable.h"
#include <unordered_map>
#include <string>
#include <iterator>

enum StoringType {
    UserType
};

class Storage {
private:
    StorageDevice* device;
    
public:
    explicit Storage(StorageDevice* device);
    virtual int add(StoringType Type, Storable* item);
    virtual std::string* retrieve(StoringType storingType, const std::string& key);
    virtual int update(StoringType Type, Storable* item);
    std::string begin();
    bool hitEOF();
    std::string next();
private:
    std::string getKey(StoringType storingType, Storable *item);
    std::string storingTypeToString(StoringType storingType);
};

#endif //PROJECT_STORAGE_H