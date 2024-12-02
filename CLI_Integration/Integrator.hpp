/**
 * @file Integrator.hpp
 * @brief Header file for the integration command dispatcher.
 *
 * This file contains the declaration of the function used to handle integration commands.
 * It includes necessary standard library headers and defines the function prototype.
 */

#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

/**
 * @brief Processes the integration command.
 *
 * This function takes an input string representing an integration command and processes it accordingly.
 *
 * @param input The integration command as a string.
 */
void integrationCommend(const std::string& input);

#endif // DISPATCHER_H
