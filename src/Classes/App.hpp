//
// Created by Surfer Boy on 17/12/2024.
//

#ifndef MY_PROJECT_APP_HPP
#define MY_PROJECT_APP_HPP
#include "iostream"
#include "../LibraryDependencies.h"
#include "../Interfaces/ICommand.hpp"
#include "../Interfaces/InputStream.hpp"
#include "../Interfaces/IResponseProtocol.hpp"
class App {
private:
    InputStream* inputStream;
    OutputStream* outputStream;
    IResponseProtocol* responseProtocol;
    std::unordered_map<std::string, ICommand*>* commands;
public:
    explicit App (std::unordered_map<std::string, ICommand*>* commands, InputStream* inputStream, OutputStream* outputStream,  IResponseProtocol* responseProtocol);
    void run();
};


#endif //MY_PROJECT_APP_HPP
