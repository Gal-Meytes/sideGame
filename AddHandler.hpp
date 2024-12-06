#ifndef ADD_HANDLER_H
#define ADD_HANDLER_H

#include "LibraryDependencies.h"

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
void handleAdd(const std::vector<std::string>& args);

/**
 * @brief Adds movies to a user's list.
 *
 * This function adds the specified movies to the list of the user identified
 * by the given user ID.
 *
 * @param userId The ID of the user to whom the movies will be added.
 * @param movieIds A vector of strings containing the IDs of the movies to be added.
 */
void add(const std::string& userId, const std::vector<std::string>& movieIds);

#endif // ADD_HANDLER_H

