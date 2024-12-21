//
// Created by Surfer Boy on 19/12/2024.
//

#include "ConsoleConnectionFactory.hpp"

IConnection *ConsoleConnectionFactory::fabricateIConnection() {
    if (numConnections > 0) {
        numConnections--;
        return new ConsoleConnection();
    }
    return nullptr;
}

ConsoleConnectionFactory::ConsoleConnectionFactory() {}
