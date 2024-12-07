
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
#include "Integrator.hpp"

int main() {
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        integrationCommend(input);
    }

    return 0;
}
