//
// Created by Surfer Boy on 19/12/2024.
//

#ifndef MY_PROJECT_CONSOLECONNECTION_HPP
#define MY_PROJECT_CONSOLECONNECTION_HPP
#include "../Interfaces/IConnection.hpp"
#include "ConsoleInputStream.hpp"
#include "ConsoleOutputStream.hpp"
#include "ConsoleErrorStream.hpp"

class ConsoleConnection : public IConnection{
private:
    InputStream * inputStream;
    OutputStream * outputStream;
    ErrorStream * errorStream;
public:
    explicit ConsoleConnection();
    ErrorStream * getErrorStream() override;
    InputStream * getInputStream() override;
    OutputStream * getOutputStream() override;
};


#endif //MY_PROJECT_CONSOLECONNECTION_HPP
