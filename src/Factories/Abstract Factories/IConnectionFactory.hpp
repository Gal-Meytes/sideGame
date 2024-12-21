//
// Created by Surfer Boy on 19/12/2024.
//

#ifndef MY_PROJECT_ICONNECTIONFACTORY_HPP
#define MY_PROJECT_ICONNECTIONFACTORY_HPP
#include "../../Interfaces/IConnection.hpp"

class IConnectionFactory {
public:
    virtual IConnection* fabricateIConnection() = 0;
};


#endif //MY_PROJECT_ICONNECTIONFACTORY_HPP
