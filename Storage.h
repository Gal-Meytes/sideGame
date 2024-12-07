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
    std::unordered_map<std::string, Storable*> items;

public:
    explicit Storage(StorageDevice* device);
    virtual int add(StoringType Type, Storable* item);
    virtual Storable* retrieve(StoringType storingType, const std::string& key);
    virtual int update(StoringType Type, Storable* item);

    // Iterator support
    using iterator = std::unordered_map<std::string, Storable*>::iterator;
    using const_iterator = std::unordered_map<std::string, Storable*>::const_iterator;

    iterator begin() { return items.begin(); }
    iterator end() { return items.end(); }
    const_iterator begin() const { return items.begin(); }
    const_iterator end() const { return items.end(); }

private:
    std::string getKey(StoringType storingType, Storable *item);
    std::string storingTypeToString(StoringType storingType);
};

#endif //PROJECT_STORAGE_H