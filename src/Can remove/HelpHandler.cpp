/**
 * @file HelpHandler.cpp
 * @brief Implementation of the help handling functionality for the Metflix application.
 */

/**
 * @brief Handles the help request by invoking the help function.
 *
 * This function is responsible for calling the help function to provide
 * assistance or guidance to the user.
 */
#include "HelpHandler.hpp"

void handleHelp() {
    std::cout << "  add [userId] [movieIds] ...\n";
    std::cout << "  recommend [userId] [movieId]\n";
    std::cout << "  help\n";
}

std::string testhelp(){
    std::string expectedHelpMessage = 
        "  add [userId] [movieIds] ...\n";
        "  recommend [userId] [movieId]\n";
        "  help\n";
        
    return expectedHelpMessage;
}
