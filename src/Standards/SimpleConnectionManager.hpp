//
// Created by Surfer Boy on 21/12/2024.
//

#ifndef MY_PROJECT_SIMPLECONNECTIONMANAGER_HPP
#define MY_PROJECT_SIMPLECONNECTIONMANAGER_HPP
#include "../Interfaces/IConnectionManager.hpp"
#include "../Factories/Abstract Factories/IConnectionFactory.hpp"
#include "../Factories/Abstract Factories/IAppFactory.hpp"
#include "../Classes/App.hpp"
#include "thread"
class SimpleConnectionManager : public IConnectionManager {
private:
    IConnectionFactory* iConnectionFactory;
    IAppFactory* iAppFactory;
public:
    SimpleConnectionManager(IConnectionFactory* iConnectionFactory, IAppFactory* iAppFactory);
    virtual void run() override;

};


#endif //MY_PROJECT_SIMPLECONNECTIONMANAGER_HPP
