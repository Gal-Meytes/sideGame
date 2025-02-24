//
// Created by Surfer Boy on 18/02/2025.
//

#ifndef MY_PROJECT_STRINGOUTPUTSTREAM_HPP
#define MY_PROJECT_STRINGOUTPUTSTREAM_HPP
#include "../Interfaces/OutputStream.hpp"
#include "iostream"
#include "vector"
class StringOutputStream : public OutputStream {
private:
    std::vector<std::string> buffer;
    std::string output;
public:
    virtual void writeLine(std::string) override;

    void flush() override;
    std::string getOutput();
};


#endif //MY_PROJECT_STRINGOUTPUTSTREAM_HPP
