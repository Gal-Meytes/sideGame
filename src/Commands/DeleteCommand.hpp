//
// Created by Surfer Boy on 17/12/2024.
//

#ifndef MY_PROJECT_DELETECOMMAND_HPP
#define MY_PROJECT_DELETECOMMAND_HPP
#include "../Interfaces/ICommand.hpp"
#include "../Interfaces/InputStream.hpp"
#include "../Interfaces/OutputStream.hpp"
#include "../Interfaces/ErrorStream.hpp"
#include "../Interfaces/IResponseProtocol.hpp"

class DeleteCommand : public ICommand {
private:
    Storage* storage;
    OutputStream* outputStream;
    ErrorStream* errorStream;
    IResponseProtocol* responseProtocol;
public:
    DeleteCommand(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream, IResponseProtocol* responseProtocol);
    virtual void execute(std::vector<std::string> arguments) override;
    virtual void printCommand() override;
    virtual std::string name() override;
};


#endif //MY_PROJECT_DELETECOMMAND_HPP
