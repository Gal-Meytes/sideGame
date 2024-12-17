//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_ICOMMANDFACTORY_HPP
#define MY_PROJECT_ICOMMANDFACTORY_HPP
#include "iostream"
#include "unordered_map"
#include "ICommand.hpp"
class ICommandFactory {
public:
    virtual std::unordered_map<std::string, ICommand*> commands();
};


#endif //MY_PROJECT_ICOMMANDFACTORY_HPP
