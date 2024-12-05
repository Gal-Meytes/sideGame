//
// Created by Surfer Boy on 30/11/2024.
//

#include "Storage.h"
class StdStorage : Storage {
    StdStorage(std::string directory) {

    }
        int add(StoringType Type, Storable *item) {
            std::string key = getKey(Type, item);
            std::string value = item->serialize();
            return device.add(key, value, NULL);
        }

        void *retrieve(StoringType Type, Storable *item) {
            std::string key = getKey(Type, item);
            return device.find(key);
        }

        int update(StoringType Type, Storable* item) {
            std::string key = getKey(Type, item);
            std::string value = item->serialize();
            return device.update(key, value, NULL);
        }

    private:
        std::string getKey(StoringType Type, Storable *item) {
            std::string typeStr = typeString(Type);
            return  typeStr + ", " + item->getIdentity();
        }

        std::string typeString(StoringType type) {
            if (type == UserType)
                return "USER";
        return "UNDEFINED";
    }

};