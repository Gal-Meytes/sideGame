//
// Created by Surfer Boy on 23/12/2024.
//

#ifndef MY_PROJECT_INTERNETCONNECTIONFACTORY_HPP
#define MY_PROJECT_INTERNETCONNECTIONFACTORY_HPP
#include "Abstract Factories/IConnectionFactory.hpp"
#include "../Interfaces/ErrorStream.hpp"
#include "../Standards/InternetConnection.hpp"
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class InternetConnectionFactory : public IConnectionFactory {
private:
    int serverSocket = -1;
    int port;
    ErrorStream* fabricationErrorStream;
public:
    InternetConnectionFactory(int port, ErrorStream* errorStream);
    IConnection * fabricateIConnection() override;
};


#endif //MY_PROJECT_INTERNETCONNECTIONFACTORY_HPP
