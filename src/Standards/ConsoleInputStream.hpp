//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_CONSOLEINPUTSTREAM_HPP
#define MY_PROJECT_CONSOLEINPUTSTREAM_HPP
#include "../Interfaces/InputStream.hpp"

class ConsoleInputStream : public InputStream{
    virtual std::string readLine();
};


#endif //MY_PROJECT_CONSOLEINPUTSTREAM_HPP
