//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_STDCOMMANDFACTORY_HPP
#define MY_PROJECT_STDCOMMANDFACTORY_HPP
#include "../Interfaces/ICommandFactory.hpp"
#include "../Commands/HelpCommand.hpp"

#include "../Commands/DeleteCommand.hpp"
#include "../Commands/GetCommand.hpp"
#include "../Commands/PatchCommand.hpp"
#include "../Commands/PostCommand.hpp"
#include "../Commands/HelpCommand.hpp"


#include "../Classes/Storage.h"
#include "../Interfaces/OutputStream.hpp"
#include "../Interfaces/ErrorStream.hpp"
#include "../Interfaces/IResponseProtocol.hpp"

class StdCommandFactory : public ICommandFactory{
private:
    std::vector<ICommand*> allCommands;
public:
    explicit StdCommandFactory(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream, IResponseProtocol* iResponseProtocol);
    virtual std::unordered_map<std::string, ICommand*>* commands() override;
};


#endif //MY_PROJECT_STDCOMMANDFACTORY_HPP
