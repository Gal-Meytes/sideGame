//
// Created by Surfer Boy on 18/12/2024.
//

#ifndef MY_PROJECT_POSTCOMMAND_HPP
#define MY_PROJECT_POSTCOMMAND_HPP
#include "../Interfaces/ICommand.hpp"
#include "../Interfaces/ICommand.hpp"
#include "../Interfaces/OutputStream.hpp"
#include "../Interfaces/ErrorStream.hpp"
#include "../Interfaces/IResponseProtocol.hpp"

class PostCommand : public ICommand{
private:
    Storage* storage;
    OutputStream* outputStream;
    ErrorStream* errorStream;
    IResponseProtocol* responseProtocol;
public:
    PostCommand(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream, IResponseProtocol* responseProtocol);
    virtual void execute(std::vector<std::string> arguments) override;
    virtual void printCommand() override;
    virtual std::string name() override;
};


#endif //MY_PROJECT_POSTCOMMAND_HPP
