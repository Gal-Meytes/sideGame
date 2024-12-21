//
// Created by Surfer Boy on 21/12/2024.
//

#ifndef MY_PROJECT_APPFACTORY_HPP
#define MY_PROJECT_APPFACTORY_HPP
#include "Abstract Factories/IAppFactory.hpp"
#include "Abstract Factories/IConnectionFactory.hpp"
#include "Abstract Factories/IStorageDeviceFactory.hpp"
#include "StreamHTTPResponseProtocolFactory.hpp"
#include "StdCommandFactory.hpp"
#include "iostream"


class AppFactory : public IAppFactory{
private:
    IStorageDeviceFactory* iStorageDeviceFactory;
public:
    explicit AppFactory(IStorageDeviceFactory* iStorageDeviceFactory);
     App* fabricateApp(IConnection* connection) override;
};


#endif //MY_PROJECT_APPFACTORY_HPP
