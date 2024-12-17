//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_IIOFACTORY_HPP
#define MY_PROJECT_IIOFACTORY_HPP
#include "InputStream.hpp"
#include "OutputStream.hpp"
#include "ErrorStream.hpp"

class IIOFactory {
public:
    virtual InputStream* InputStream() = 0;
    virtual OutputStream* OutputStream() = 0;
    virtual ErrorStream* ErrorStream() = 0;
};


#endif //MY_PROJECT_IIOFACTORY_HPP
