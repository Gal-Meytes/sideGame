//
// Created by Surfer Boy on 21/12/2024.
//

#include "AppFactory.hpp"
AppFactory::AppFactory(IStorageDeviceFactory* iStorageDeviceFactory) {
    this->iStorageDeviceFactory = iStorageDeviceFactory;
}
App* AppFactory::fabricateApp(IConnection* connection) {

    InputStream* inputStream = connection->getInputStream();
    OutputStream* outputStream = connection->getOutputStream();
    ErrorStream* errorStream = connection->getErrorStream();

    Storage* storage = new Storage(iStorageDeviceFactory->fabricateStorageDevice());

    IResponseProtocolFactory* iResponseProtocolFactory = new StreamHTTPResponseProtocolFactory(outputStream);
    IResponseProtocol* responseProtocol = iResponseProtocolFactory->fabricateResponseProtocol();

    ICommandFactory* commandFactory = new StdCommandFactory(storage, outputStream, errorStream, responseProtocol);

    App* app = new App(commandFactory->commands(), inputStream, outputStream, responseProtocol);
    return app;
}