
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

#include "Factories/IIOFactory.hpp"
#include "Factories/ConsoleIOFactory.hpp"
#include "Factories/StdCommandFactory.hpp"
#include "Factories/IStorageDeviceFactory.hpp"
#include "Factories/FileStorageDeviceFactory.hpp"
#include "Classes/App.hpp"
int main() {
    std::string input;

    while (true) {
        //std::getline(std::cin, input);
//        AppData* appData = new AppData();
        std::string folderDir = "/mnt/c/Users/Surfer Boy/OneDrive/Desktop/Study/CS/University/Advanced System Programming/forPhotos";
        IIOFactory* ioFactory = new ConsoleIOFactory();
        InputStream* inputStream = ioFactory->fabricateInputStream();
        OutputStream* outputStream = ioFactory->fabricateOutputStream();
        ErrorStream* errorStream = ioFactory->fabricateErrorStream();
        IStorageDeviceFactory* storageDeviceFactory = new FileStorageDeviceFactory(&folderDir);
        Storage* storage = new Storage(storageDeviceFactory->storageDevice());

        ICommandFactory* commandFactory = new StdCommandFactory(storage, outputStream, errorStream);
        App* app = new App(commandFactory->commands(), inputStream);
        app->run();
//        integrationCommend(input);
    }

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
