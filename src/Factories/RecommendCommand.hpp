//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_RECOMMENDCOMMAND_HPP
#define MY_PROJECT_RECOMMENDCOMMAND_HPP
#include "../Interfaces/ICommand.hpp"
#include "../Classes/Storage.h"
#include "../Classes/StorageIterator.hpp"
#include "../Interfaces/ErrorStream.hpp"
class RecommendCommand : public ICommand {
private:
    Storage* storage;
    OutputStream* outputStream;
    ErrorStream* errorStream;
public:
    RecommendCommand(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream);
    virtual void execute(std::vector<std::string> arguments) override;
    virtual void printCommand() override;
    virtual std::string name() override;
};
#endif //MY_PROJECT_RECOMMENDCOMMAND_HPP
