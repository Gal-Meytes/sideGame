//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_OUTPUTSTREAM_HPP
#define MY_PROJECT_OUTPUTSTREAM_HPP
#include "iostream"

class OutputStream {
public:
    virtual void writeLine(std::string) = 0;
};


#endif //MY_PROJECT_OUTPUTSTREAM_HPP
