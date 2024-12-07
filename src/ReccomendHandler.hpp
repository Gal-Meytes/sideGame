
#ifndef RECCOMEND_HANDLER_H
#define RECCOMEND_HANDLER_H

#include <vector>
#include <string>
#include <iostream>
#include "Storage.h"
#include <functional>
#include "StorageIterator.hpp"

/**
 * @brief Handles the recommendation process based on the provided arguments.
 * 
 * This function processes the given arguments to handle recommendations.
 * 
 * @param args A vector of strings containing the arguments for recommendation handling.
 */
void handleReccomend(Storage &storage, const std::vector<std::string>& args);

std::string* RecommendTest(
    Storage& storage,
    const std::vector<std::string>& args,
    std::function<bool(const std::pair<std::string, int>&, const std::pair<std::string, int>&)> customSort
);

#endif // ADD_HANDLER_H
