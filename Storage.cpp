#include "Storage.h"

//public
Storage::Storage(StorageDevice* device) {
    this->device = device;
}

int Storage::add(StoringType storingType, Storable *item) {
    if (item == nullptr)
        return 0;
    std::string key = getKey(storingType, item);
    std::string value = item->serialize();
    return device->add(key, value, nullptr);
}

void *Storage::retrieve(StoringType storingType, Storable *item) {
    if (item == nullptr)
        return nullptr;
    std::string key = getKey(storingType, item);
    return device->find(key);
}

int Storage::update(StoringType storingType, Storable *item) {
    if (item == nullptr)
        return 0;
    std::string key = getKey(storingType, item);
    std::string value = item->serialize();
    return device->update(key, value, nullptr);
}

//private
std::string Storage::getKey(StoringType storingType, Storable *item) {
    std::string storingTypeStr = storingTypeToString(storingType);
    return storingTypeStr + ", " + item->getIdentity();
}

std::string Storage::storingTypeToString(StoringType storingType) {
    if (storingType == UserType)
        return "USER";
    return "UNDEFINED";
}
//protected