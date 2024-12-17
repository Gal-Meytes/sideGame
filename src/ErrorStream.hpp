//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_ERRORSTREAM_HPP
#define MY_PROJECT_ERRORSTREAM_HPP
#include "iostream"

class ErrorStream {
public:
    virtual void outputError(std::string error) = 0;
};


#endif //MY_PROJECT_ERRORSTREAM_HPP
