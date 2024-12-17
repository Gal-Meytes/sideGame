//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_ICOMMAND_HPP
#define MY_PROJECT_ICOMMAND_HPP
#include "../LibraryDependencies.h"
#include "../Classes/Storage.h"
#include "../Classes/AppData.hpp"
#include "OutputStream.hpp"

class ICommand {
public:
    virtual void execute(std::vector<std::string> arguments) = 0;
    virtual void printCommand() = 0;
    virtual std::string name() = 0;
};


#endif //MY_PROJECT_ICOMMAND_HPP
