//
// Created by Surfer Boy on 19/12/2024.
//

#ifndef MY_PROJECT_CONSOLECONNECTIONFACTORY_HPP
#define MY_PROJECT_CONSOLECONNECTIONFACTORY_HPP
#include "IConnectionFactory.hpp"
#include "../Standards/ConsoleConnection.hpp"
class ConsoleConnectionFactory : public IConnectionFactory {
private:
    int numConnections = 1;
public:
    ConsoleConnectionFactory();
    IConnection * fabricateIConnection() override;
};


#endif //MY_PROJECT_CONSOLECONNECTIONFACTORY_HPP
