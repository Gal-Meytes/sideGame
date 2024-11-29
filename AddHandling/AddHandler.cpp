#include "AddHandler.hpp"

/**
 * @brief Handles the 'add' command by extracting the user ID and movie IDs from the arguments
 *        and delegating the operation to the add function.
 * 
 * @param args A vector of strings where the first element is the user ID and the remaining elements are movie IDs.
 *             The 'add' command requires at least 2 arguments.
 * 
 * @note If the number of arguments is less than 2, an error message is printed to std::cerr.
 */
void handleAdd(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cerr << "Error: 'add' command requires at least 2 arguments." << std::endl;
        return;
    }

    // Extract user ID and movie IDs
    std::string userId = args[0];
    std::vector<std::string> movieIds(args.begin() + 1, args.end());

    // Delegate the operation to the add function
    add(userId, movieIds);
}
