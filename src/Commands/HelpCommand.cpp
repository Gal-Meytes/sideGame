//
// Created by Surfer Boy on 11/12/2024.
//

#include "HelpCommand.hpp"
#include "iostream"
#include "sstream"
HelpCommand::HelpCommand(std::vector<ICommand *> commands,
                         OutputStream *outputStream) {
    this->commands = commands;
    this->commands.push_back(this);
    this->outputStream = outputStream;
}
void HelpCommand::printCommand() {
    outputStream->writeLine("  help\n");
}
void HelpCommand::execute(std::vector<std::string> arguments) {
    for (ICommand* command : commands) {
        command->printCommand();
    }
}
std::string HelpCommand::name() {
    return "help";
}