//
// Created by Surfer Boy on 11/12/2024.
//

#include "StdCommandFactory.hpp"
StdCommandFactory::StdCommandFactory(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream, IResponseProtocol* responseProtocol) {
    AddCommand* addCommand = new AddCommand(storage, outputStream, errorStream, responseProtocol);
    RecommendCommand* recommendCommand = new RecommendCommand(storage, outputStream, errorStream, responseProtocol);

    this->allCommands.push_back(addCommand);
    this->allCommands.push_back(recommendCommand);

    HelpCommand* helpCommand = new HelpCommand(allCommands, outputStream);
    this->allCommands.push_back(helpCommand);
}

std::unordered_map<std::string, ICommand *>* StdCommandFactory::commands() {
    std::unordered_map <std::string, ICommand*>* map = new std::unordered_map <std::string, ICommand*>();
    for (ICommand* command : this->allCommands) {
        (*map)[command->name()] = command;
    }
    return map;
}