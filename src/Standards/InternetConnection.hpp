//
// Created by Surfer Boy on 21/12/2024.
//

#ifndef MY_PROJECT_INTERNETCONNECTION_HPP
#define MY_PROJECT_INTERNETCONNECTION_HPP
#include "../Interfaces/IConnection.hpp"
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <cstring>
#include <string>
#include "vector"

class InternetConnection :  public IConnection, public InputStream, public OutputStream, public ErrorStream {
    std::vector<std::string> log;
    ErrorStream* errorStream;
    int clientSocket;
public:
    InternetConnection( int port, ErrorStream* errorStream);
    ~InternetConnection();
    InputStream * getInputStream() override;
    OutputStream * getOutputStream() override;
    ErrorStream * getErrorStream() override;

    std::string readLine() override;
    void writeLine(std::string) override;
    void flush() override;
    void outputError(std::string error) override;
private:
//    void acceptConnection();

};


#endif //MY_PROJECT_INTERNETCONNECTION_HPP
