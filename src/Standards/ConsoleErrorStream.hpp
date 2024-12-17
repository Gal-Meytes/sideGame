//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_CONSOLEERRORSTREAM_HPP
#define MY_PROJECT_CONSOLEERRORSTREAM_HPP
#include "../Interfaces/ErrorStream.hpp"

class ConsoleErrorStream : public ErrorStream{
public:
    virtual void outputError(std::string error) override;
};


#endif //MY_PROJECT_CONSOLEERRORSTREAM_HPP
