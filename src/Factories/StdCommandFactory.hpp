//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_STDCOMMANDFACTORY_HPP
#define MY_PROJECT_STDCOMMANDFACTORY_HPP
#include "../Interfaces/ICommandFactory.hpp"
#include "../Commands/AddCommand.hpp"
#include "../Commands/HelpCommand.hpp"
#include "RecommendCommand.hpp"
#include "../Classes/Storage.h"
#include "../Interfaces/OutputStream.hpp"
#include "../Interfaces/ErrorStream.hpp"

class StdCommandFactory : public ICommandFactory{
private:
    std::vector<ICommand*> allCommands;
public:
    explicit StdCommandFactory(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream);
    virtual std::unordered_map<std::string, ICommand*>* commands() override;
};


#endif //MY_PROJECT_STDCOMMANDFACTORY_HPP
