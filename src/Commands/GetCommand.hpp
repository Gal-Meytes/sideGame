//
// Created by Surfer Boy on 17/12/2024.
//

#ifndef MY_PROJECT_GETCOMMAND_HPP
#define MY_PROJECT_GETCOMMAND_HPP
#include "../Interfaces/ICommand.hpp"
#include "../Interfaces/OutputStream.hpp"
#include "../Interfaces/ErrorStream.hpp"
#include "../Interfaces/IResponseProtocol.hpp"
#include "../Classes/Storage.h"
#
class GetCommand : public ICommand {
private:
    Storage* storage;
    OutputStream* outputStream;
    ErrorStream* errorStream;
    IResponseProtocol* responseProtocol;
public:
    explicit GetCommand(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream, IResponseProtocol* responseProtocol);
    void execute(std::vector<std::string> arguments) override;
    void printCommand() override;
    std::string name() override;
};
#endif //MY_PROJECT_GETCOMMAND_HPP
