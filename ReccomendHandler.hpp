
#ifndef RECCOMEND_HANDLER_H
#define RECCOMEND_HANDLER_H

#include <vector>
#include <string>
#include <iostream>
#include "Storage.h"

/**
 * @brief Handles the recommendation process based on the provided arguments.
 * 
 * This function processes the given arguments to handle recommendations.
 * 
 * @param args A vector of strings containing the arguments for recommendation handling.
 */
void handleReccomend(Storage &storage, const std::vector<std::string>& args);

#endif // ADD_HANDLER_H
