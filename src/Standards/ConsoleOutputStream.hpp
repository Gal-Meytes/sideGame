//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_CONSOLEOUTPUTSTREAM_HPP
#define MY_PROJECT_CONSOLEOUTPUTSTREAM_HPP
#include "../Interfaces/OutputStream.hpp"
#include "iostream"
#include "vector"
class ConsoleOutputStream : public OutputStream {
private:
    std::vector<std::string> buffer;
public:
    virtual void writeLine(std::string) override;
    void flush() override;
};


#endif //MY_PROJECT_CONSOLEOUTPUTSTREAM_HPP
