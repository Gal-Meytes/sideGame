//
// Created by Surfer Boy on 21/12/2024.
//

#ifndef MY_PROJECT_IAPPFACTORY_HPP
#define MY_PROJECT_IAPPFACTORY_HPP
#include "../../Classes/App.hpp"
#include "../../Interfaces/IConnection.hpp"

class IAppFactory {
public:
    virtual App* fabricateApp(IConnection* connection) = 0;
};


#endif //MY_PROJECT_IAPPFACTORY_HPP
