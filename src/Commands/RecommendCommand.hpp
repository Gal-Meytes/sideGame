//
// Created by Surfer Boy on 17/12/2024.
//

#ifndef MY_PROJECT_RECOMMENDCOMMAND_HPP
#define MY_PROJECT_RECOMMENDCOMMAND_HPP
#include "../Interfaces/ICommand.hpp"
#include "../Interfaces/OutputStream.hpp"
#include "../Interfaces/ErrorStream.hpp"
#include "../Interfaces/IResponseProtocol.hpp"
#include "../Classes/Storage.h"
#
class RecommendCommand : public ICommand {
private:
    Storage* storage;
    OutputStream* outputStream;
    ErrorStream* errorStream;
    IResponseProtocol* responseProtocol;
public:
    explicit RecommendCommand(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream, IResponseProtocol* responseProtocol);
    void execute(std::vector<std::string> arguments) override;
    void printCommand() override;
    std::string name() override;
};
#endif //MY_PROJECT_RECOMMENDCOMMAND_HPP
