//
// Created by Surfer Boy on 09/12/2024.
//

#include "StorageIterator.hpp"

StorageIterator::StorageIterator(Storage* storage, StoringType type) {
    this->storage = storage;
    this->type = type;
    this->offset = 0;
}
std::string* StorageIterator::getNext() {
    if (offset == -1)
        return nullptr;
    std::string* identity = storage->getKey(type, offset, &offset);
    if (identity == nullptr)
        return nullptr;
    User user = User(*identity, nullptr);
    return storage->retrieve(type, &user);
}