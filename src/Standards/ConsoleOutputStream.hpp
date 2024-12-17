//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_CONSOLEOUTPUTSTREAM_HPP
#define MY_PROJECT_CONSOLEOUTPUTSTREAM_HPP
#include "OutputStream.hpp"

class ConsoleOutputStream : public OutputStream{
    virtual void writeLine(std::string) override;
};


#endif //MY_PROJECT_CONSOLEOUTPUTSTREAM_HPP
