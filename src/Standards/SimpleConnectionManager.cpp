//
// Created by Surfer Boy on 21/12/2024.
//

#include "SimpleConnectionManager.hpp"
SimpleConnectionManager::SimpleConnectionManager(int numConnections, IConnectionFactory* iConnectionFactory, IAppFactory* iAppFactory) {
    this->numConnections = numConnections;
    this->iConnectionFactory = iConnectionFactory;
    this->iAppFactory =iAppFactory;
}

void SimpleConnectionManager::run() {
    std::vector<std::thread > threads;
    while (true) {
        IConnection *connection = iConnectionFactory->fabricateIConnection();
        if (connection == nullptr)
            continue;
        App* newApp = iAppFactory->fabricateApp(connection);
        new std::thread(&App::run, newApp);
    }
//    for (std::thread& _thread: threads)
//        if (_thread.joinable())
//        _threadjoin();
}