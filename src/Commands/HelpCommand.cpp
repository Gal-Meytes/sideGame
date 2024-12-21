//
// Created by Surfer Boy on 11/12/2024.
//

#include "HelpCommand.hpp"
#include "iostream"
#include "sstream"
HelpCommand::HelpCommand(std::vector<ICommand *> commands,
                         OutputStream *outputStream, IResponseProtocol* iResponseProtocol) {
    this->commands = commands;
    this->commands.push_back(this);
    this->outputStream = outputStream;
    this->iResponseProtocol = iResponseProtocol;
}
void HelpCommand::printCommand() {
    outputStream->writeLine("help");
}
void HelpCommand::execute(std::vector<std::string> arguments) {
    iResponseProtocol->Ok();
    outputStream->writeLine("");
    for (ICommand* command : commands) {
        command->printCommand();
    }
}
std::string HelpCommand::name() {
    return "help";
}