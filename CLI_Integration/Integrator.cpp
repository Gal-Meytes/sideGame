#include "Integrator.hpp"
#include "addHandler.h"
#include "helpHandler.h"
#include "recommendHandler.h"

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
        handleRecommend(args);
    } else {
        std::cerr << "Unknown command. Type 'help' to see available commands." << std::endl;
    }
}
