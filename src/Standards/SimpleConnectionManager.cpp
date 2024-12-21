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
    std::vector<std::thread *> threads;
    for (;numConnections>0; numConnections--) {
        IConnection *connection = iConnectionFactory->fabricateIConnection();
        if (connection == nullptr)
            break;
        App* newApp = iAppFactory->fabricateApp(connection);
        std::thread newThread(&App::run, newApp);
        newThread.join();
        threads.push_back(&newThread);
    }
    for (std::thread * _thread: threads)
        if (_thread->joinable())
        _thread->join();
}