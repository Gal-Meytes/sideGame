//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_STDCOMMANDFACTORY_HPP
#define MY_PROJECT_STDCOMMANDFACTORY_HPP
#include "ICommandFactory.hpp"
#include "AddCommand.hpp"
#include "HelpCommand.hpp"
#include "RecommendCommand.hpp"
#include "Storage.h"
#include "OutputStream.hpp"
#include "ErrorStream.hpp"

class StdCommandFactory : public ICommandFactory{
private:
    std::vector<ICommand*> allCommands;
public:
    explicit StdCommandFactory(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream);
    virtual std::unordered_map<std::string, ICommand*> commands() override;
};


#endif //MY_PROJECT_STDCOMMANDFACTORY_HPP
