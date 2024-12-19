#include "../Classes/Storage.h"

//public
Storage::Storage(StorageDevice* device) {
    this->device = device;
}

int Storage::add(StoringType storingType, Storable *item) {
    if (item == nullptr)
        return 0;
    std::string key = getKey(storingType, item);
    std::string value = item->serialize();
    if (device->mutex() == false)
        return 0;
    int result = device->add(key, value, nullptr);
    device->releaseMutex();
    return result;
}

std::string * Storage::retrieve(StoringType storingType, Storable *item) {
    if (item == nullptr)
        return nullptr;
    std::string key = getKey(storingType, item);
    device->mutex();
    std::string* res = device->find(key);
    device->releaseMutex();
    return res;
}

std::string * Storage::getKey(StoringType storingType, off_t offset, off_t* nextIndex) {
    std::string receivedKey;
    do {
        offset = device->getKey(offset, &receivedKey);
    } while (!receivedKey.empty() && storingTypeOfString(receivedKey) != storingType && offset != -1);
    *nextIndex = offset;
    if (receivedKey.empty())
        return nullptr;
    std::string* returnStr = new std::string (getIdentityFromKey(receivedKey));
    return returnStr;
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
StoringType Storage::storingTypeOfString(std::string str) {
    if (strncmp(str.c_str(), "USER", strlen("USER")) == 0)
        return UserType;
    return Undefined;
}
std::string Storage::getIdentityFromKey(std::string key) {
    if (strncmp(key.c_str(), "USER", strlen("USER")) == 0) {
        return key.substr(strlen("USER") + strlen(" ") + 1);
    }
    return key;
}