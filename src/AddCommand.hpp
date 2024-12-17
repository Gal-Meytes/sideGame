//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_ADDCOMMAND_HPP
#define MY_PROJECT_ADDCOMMAND_HPP
#include "ICommand.hpp"
#include "OutputStream.hpp"
#include "ErrorStream.hpp"
class AddCommand : public ICommand {
private:
    Storage* storage;
    OutputStream* outputStream;
    ErrorStream* errorStream;
public:
    AddCommand(Storage* storage, OutputStream* outputStream, ErrorStream* errorStream);
    virtual void execute(std::vector<std::string> arguments) override;
    virtual void printCommand() override;
    virtual std::string name() override;
};


#endif //MY_PROJECT_ADDCOMMAND_HPP
