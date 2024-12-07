#include "ReccomendHandler.hpp"
#include "Recommend.hpp"
/**
 * @brief Handles the 'reccomend' command by delegating to the reccomend function.
 * 
 * This function expects exactly two arguments: a user ID and a movie ID. If the number
 * of arguments is not equal to 2, it prints an error message and returns.
 * 
 * @param args A vector of strings containing the arguments for the 'reccomend' command.
 *             The first argument should be the user ID and the second argument should be the movie ID.
 */


void handleReccomend(Storage& storage, const std::vector<std::string>& args) {
    if (args.size() == 2) {
    std::cout << "Recommending movies for user " << args[0] << " based on movie " << args[1] << ".\n" << recommend(storage, args) << std::endl;

    }
}

