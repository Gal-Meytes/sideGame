//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_HELPCOMMAND_HPP
#define MY_PROJECT_HELPCOMMAND_HPP
#include "ICommand.hpp"
#include "OutputStream.hpp"
class HelpCommand : public ICommand {
private:
    std::vector<ICommand*> commands;
    OutputStream* outputStream;

public:
    HelpCommand(std::vector<ICommand*> commands,
    OutputStream* outputStream);
    virtual void execute(std::vector<std::string> arguments) override;
    virtual void printCommand() override;
    virtual std::string name() override;
};


#endif //MY_PROJECT_HELPCOMMAND_HPP
