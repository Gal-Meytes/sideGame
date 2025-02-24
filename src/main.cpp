
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
static int is_number(const char *str) {
    char* endptr;

    // Use strtol to convert the string to a long integer
    strtol(str, &endptr, 10);

    // Check if there were any non-digit characters after the conversion
    // If endptr points to the null terminator, the entire string is a valid long
    return *endptr == '\0';
}
int main(int argc, char* argv[]) {
    if (argc < 2)
        return 0;
    if (is_number(argv[1]) == 0)
        return 0;

    std::string input;
    std::string folderDir = "/app/data";

    IStorageDeviceFactory* storageDeviceFactory = new FileStorageDeviceFactory(&folderDir);
    IAppFactory* appFactory = new AppFactory(storageDeviceFactory);
    IConnectionFactory* iConnectionFactory = new InternetConnectionFactory((int)strtol(argv[1], nullptr, 10), new ConsoleErrorStream());

    IConnectionManager* connectionManager = new SimpleConnectionManager(iConnectionFactory, appFactory);

    connectionManager->run();
    return 0;
}
