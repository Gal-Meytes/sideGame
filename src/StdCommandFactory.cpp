//
// Created by Surfer Boy on 11/12/2024.
//

#include "StdCommandFactory.hpp"
StdCommandFactory::StdCommandFactory(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream) {
    AddCommand* addCommand = new AddCommand(storage, outputStream, errorStream);
    RecommendCommand* recommendCommand = new RecommendCommand(storage, outputStream, errorStream);

    this->allCommands.push_back(addCommand);
    this->allCommands.push_back(recommendCommand);

    HelpCommand* helpCommand = new HelpCommand(allCommands, outputStream);
    this->allCommands.push_back(helpCommand);
}

std::unordered_map<std::string, ICommand *> StdCommandFactory::commands() {
    std::unordered_map <std::string, ICommand*> map;
    for (ICommand* command : this->allCommands) {
        map[command->name()] = command;
    }
    return map;
}