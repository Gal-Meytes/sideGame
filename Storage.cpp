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

Storable* Storage::retrieve(StoringType storingType, const std::string& key) {
    void* rawData = device->find(key);

    if (rawData == nullptr) {
        return nullptr; // Not found
    }

    // Use dynamic_cast to safely convert void* to Storable*
    Storable* storable = dynamic_cast<Storable*>(static_cast<Storable*>(rawData));

    if (!storable) {
        std::cerr << "Error: Retrieved object is not of type Storable.\n";
        return nullptr;
    }

    return storable;
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