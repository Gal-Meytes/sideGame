
#ifndef RECCOMEND_HANDLER_H
#define RECCOMEND_HANDLER_H

#include <vector>
#include <string>
#include <iostream>

/**
 * @brief Handles the recommendation process based on the provided arguments.
 * 
 * This function processes the given arguments to handle recommendations.
 * 
 * @param args A vector of strings containing the arguments for recommendation handling.
 */
void handleReccomend(const std::vector<std::string>& args);

/**
 * @brief Recommends a movie to a user.
 * 
 * This function generates a movie recommendation for a specific user.
 * 
 * @param userId The ID of the user to whom the recommendation is made.
 * @param movieId The ID of the movie being recommended.
 */
void reccomend(const std::string& userId, const std::string movieId);

#endif // ADD_HANDLER_H
