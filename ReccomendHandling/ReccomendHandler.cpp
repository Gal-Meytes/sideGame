#include "ReccomendHandler.hpp"

/**
 * @brief Handles the 'reccomend' command by delegating to the reccomend function.
 * 
 * This function expects exactly two arguments: a user ID and a movie ID. If the number
 * of arguments is not equal to 2, it prints an error message and returns.
 * 
 * @param args A vector of strings containing the arguments for the 'reccomend' command.
 *             The first argument should be the user ID and the second argument should be the movie ID.
 */
void handleReccomend(const std::vector<std::string>& args) {
    if (args.size() != 2) {
        std::cerr << "Error: 'reccomend' command requires at least 2 arguments." << std::endl;
        return;
    }

    // Extract user ID and movie ID
    std::string userId = args[0];
    std::string movieId = args[1];

    // Delegate the operation to the reccomend function
    reccomend(userId, movieId);
}
