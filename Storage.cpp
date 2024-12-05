//
// Created by Surfer Boy on 30/11/2024.
//

#include "Storage.h"
int Storage::add(StoringType Type, void* item) {
    if (Type == UserType) {
        User* userItem = (User *) item;
        this->device.add(userItem->Identify());
        this->device.add(", ");
        this->device.add(userItem->toString());
    }
}
