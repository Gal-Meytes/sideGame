//
// Created by Surfer Boy on 09/12/2024.
//

#ifndef PROJECT_STORAGE_ITERATOR_HPP
#define PROJECT_STORAGE_ITERATOR_HPP
#include "../LibraryDependencies.h"
#include "Storage.h"

class StorageIterator {
private:
    Storage* storage;
    StoringType type;
    off_t offset;
public:
    explicit StorageIterator(Storage* storage, StoringType type);
    std::string* getNext();
};


#endif //PROJECT_STORAGE_ITERATOR_HPP
