//
// Created by Surfer Boy on 19/12/2024.
//

#include "ConsoleConnection.hpp"
ConsoleConnection::ConsoleConnection() {
    this->inputStream = new ConsoleInputStream();
    this->outputStream = new ConsoleOutputStream();
    this->errorStream = new ConsoleErrorStream();
}

InputStream *ConsoleConnection::getInputStream() {
    return this->inputStream;
}

OutputStream *ConsoleConnection::getOutputStream() {
    return this->outputStream;
}

ErrorStream *ConsoleConnection::getErrorStream() {
    return this->errorStream;
}