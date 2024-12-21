//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_HELPCOMMAND_HPP
#define MY_PROJECT_HELPCOMMAND_HPP
#include "../Interfaces/ICommand.hpp"
#include "../Interfaces/OutputStream.hpp"
#include "../Interfaces/IResponseProtocol.hpp"
class HelpCommand : public ICommand {
private:
    std::vector<ICommand*> commands;
    OutputStream* outputStream;
    IResponseProtocol* iResponseProtocol;

public:
    HelpCommand(std::vector<ICommand*> commands,
    OutputStream* outputStream, IResponseProtocol* iResponseProtocol);
    virtual void execute(std::vector<std::string> arguments) override;
    virtual void printCommand() override;
    virtual std::string name() override;
};


#endif //MY_PROJECT_HELPCOMMAND_HPP
