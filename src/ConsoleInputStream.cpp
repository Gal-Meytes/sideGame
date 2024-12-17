//
// Created by Surfer Boy on 11/12/2024.
//

#include "ConsoleInputStream.hpp"

std::string ConsoleInputStream::readLine() {
    std::string toReturn;
    std::getline(std::cin, toReturn, '\n');
    return toReturn;
}