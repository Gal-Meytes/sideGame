//
// Created by Surfer Boy on 21/12/2024.
//

#ifndef MY_PROJECT_SIMPLECONNECTIONMANAGER_HPP
#define MY_PROJECT_SIMPLECONNECTIONMANAGER_HPP
#include "../Interfaces/IConnectionManager.hpp"
#include "../Factories/IConnectionFactory.hpp"
#include "../Factories/IAppFactory.hpp"
#include "../Classes/App.hpp"
#include "thread"
class SimpleConnectionManager : public IConnectionManager {
private:
    int numConnections;
    IConnectionFactory* iConnectionFactory;
    IAppFactory* iAppFactory;
public:
    SimpleConnectionManager(int NumConnections, IConnectionFactory* iConnectionFactory, IAppFactory* iAppFactory);
    virtual void run() override;

};


#endif //MY_PROJECT_SIMPLECONNECTIONMANAGER_HPP
