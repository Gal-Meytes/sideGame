
/**
 * @file main.cpp
 * @brief Entry point for the CLI Integration of Metflix application.
 * 
 * This file contains the main function which continuously reads user input
 * from the standard input and processes it using the integrationCommend function.
 */

/**
 * @brief Main function of the CLI Integration.
 * 
 * This function runs an infinite loop that reads user input from the standard input
 * and passes it to the integrationCommend function for processing.
 * 
 * @return int Returns 0 upon successful execution.
 */

#include "Factories/Abstract Factories/IIOFactory.hpp"
#include "Factories/Abstract Factories/IStorageDeviceFactory.hpp"
#include "Factories/FileStorageDeviceFactory.hpp"
#include "Factories/Abstract Factories/IConnectionFactory.hpp"
#include "Factories/ConsoleConnectionFactory.hpp"
#include "Factories/InternetConnectionFactory.hpp"
#include "Factories/Abstract Factories/IAppFactory.hpp"
#include "Factories/AppFactory.hpp"
#include "Interfaces/IConnectionManager.hpp"
#include "Standards/SimpleConnectionManager.hpp"
int main() {
    std::string input;

        int numConnections = 10;
        std::string folderDir = "/mnt/c/Users/Surfer Boy/OneDrive/Desktop/Study/CS/University/Advanced System Programming/forPhotos";

        IStorageDeviceFactory* storageDeviceFactory = new FileStorageDeviceFactory(&folderDir);
        IAppFactory* appFactory = new AppFactory(storageDeviceFactory);
        IConnectionFactory* iConnectionFactory = new InternetConnectionFactory(12345, new ConsoleErrorStream());

        IConnectionManager* connectionManager = new SimpleConnectionManager(numConnections, iConnectionFactory, appFactory);

        connectionManager->run();
    return 0;
}
/*
 * add_executable(runTests
    test.cpp
    cli_functions.cpp
    StorageDevice.h
    AddHandler.cpp
    HelpHandler.cpp
    Storable.h
    Storage.cpp
    User.cpp  # Include all necessary files
)
 */
