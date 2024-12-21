//
// Created by Surfer Boy on 19/12/2024.
//

#ifndef MY_PROJECT_ICONNECTION_HPP
#define MY_PROJECT_ICONNECTION_HPP
#include "InputStream.hpp"
#include "OutputStream.hpp"
#include "ErrorStream.hpp"

class IConnection {
public:
    virtual InputStream* getInputStream() = 0;
    virtual OutputStream* getOutputStream() = 0;
    virtual ErrorStream* getErrorStream() = 0;

};


#endif //MY_PROJECT_ICONNECTION_HPP
