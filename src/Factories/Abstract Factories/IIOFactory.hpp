//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_IIOFACTORY_HPP
#define MY_PROJECT_IIOFACTORY_HPP
#include "../../Interfaces/InputStream.hpp"
#include "../../Interfaces/OutputStream.hpp"
#include "../../Interfaces/ErrorStream.hpp"

class IIOFactory {
public:
    virtual InputStream* fabricateInputStream() = 0;
    virtual OutputStream* fabricateOutputStream() = 0;
    virtual ErrorStream* fabricateErrorStream() = 0;
};


#endif //MY_PROJECT_IIOFACTORY_HPP
