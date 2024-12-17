//
// Created by Surfer Boy on 17/12/2024.
//

#ifndef MY_PROJECT_APP_HPP
#define MY_PROJECT_APP_HPP
#include "iostream"
#include "../LibraryDependencies.h"
#include "../Interfaces/ICommand.hpp"
#include "../Interfaces/InputStream.hpp"
class App {
private:
    InputStream* inputStream;
    std::unordered_map<std::string, ICommand*>* commands;
public:
    explicit App (std::unordered_map<std::string, ICommand*>* commands, InputStream* inputStream);
    void run();
};


#endif //MY_PROJECT_APP_HPP
