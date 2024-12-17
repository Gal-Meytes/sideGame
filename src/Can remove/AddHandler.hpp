#ifndef ADD_HANDLER_H
#define ADD_HANDLER_H

#include <vector>
#include <string>
#include <iostream>
#include "cli_functions.hpp"

/**
 * @file AddHandler.hpp
 * @brief Header file for handling addition operations in Metflix.
 *
 * This file contains the declarations for functions that handle adding movies
 * to a user's list in the Metflix application.
 */

 /**
    * @brief Handles the addition operation based on the provided arguments.
    *
    * This function processes the given arguments and performs the necessary
    * operations to add movies to a user's list.
    *
    * @param args A vector of strings containing the arguments for the add operation.
    */
void handleAdd(const std::vector<std::string>& args, Storage& storage);

#endif // ADD_HANDLER_H

