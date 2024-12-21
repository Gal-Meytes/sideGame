//
// Created by Surfer Boy on 11/12/2024.
//

#include "StdCommandFactory.hpp"
StdCommandFactory::StdCommandFactory(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream, IResponseProtocol* responseProtocol) {

    DeleteCommand* deleteCommand = new DeleteCommand(storage, outputStream, errorStream, responseProtocol);
    GetCommand* getCommand = new GetCommand(storage, outputStream, errorStream, responseProtocol);
    PatchCommand* patchCommand = new PatchCommand(storage, outputStream, errorStream, responseProtocol);
    PostCommand* postCommand = new PostCommand(storage, outputStream, errorStream, responseProtocol);

    this->allCommands.push_back(deleteCommand);
    this->allCommands.push_back(getCommand);
    this->allCommands.push_back(patchCommand);
    this->allCommands.push_back(postCommand);

    HelpCommand* helpCommand = new HelpCommand(allCommands, outputStream, responseProtocol);
    this->allCommands.push_back(helpCommand);
}

std::unordered_map<std::string, ICommand *>* StdCommandFactory::commands() {
    std::unordered_map <std::string, ICommand*>* map = new std::unordered_map <std::string, ICommand*>();
    for (ICommand* command : this->allCommands) {
        (*map)[command->name()] = command;
    }
    return map;
}