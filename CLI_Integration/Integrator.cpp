#include "Integrator.hpp"
#include "AddHandler.hpp"
#include "HelpHandler.hpp"
#include "ReccomendHandler.hpp"

/**
 * @brief Processes a given command input and executes the corresponding function.
 *
 * This function takes a string input, parses it to extract the command and its arguments,
 * and then calls the appropriate handler function based on the command.
 *
 * @param input The command input as a string. The first word is treated as the command,
 *              and the subsequent words are treated as arguments.
 *
 * Supported commands:
 * - "help": Calls the handleHelp() function to display help information.
 * - "add": Calls the handleAdd(const std::vector<std::string>& args) function to add an item.
 * - "recommend": Calls the handleRecommend(const std::vector<std::string>& args) function to provide recommendations.
 *
 * If the command is not recognized, an error message is printed to the standard error output.
 */
void integrationCommend(const std::string& input) {
    std::istringstream iss(input);
    std::string command;
    iss >> command;

    std::vector<std::string> args;
    std::string arg;
    while (iss >> arg) {
        args.push_back(arg);
    }

    if (command == "help") {
        handleHelp();
    } else if (command == "add") {
        handleAdd(args);
    } else if (command == "recommend") {
        handleReccomend(args);
    } else {
        std::cerr << "Unknown command. Type 'help' to see available commands." << std::endl;
    }
}
