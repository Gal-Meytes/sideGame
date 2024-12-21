//
// Created by Surfer Boy on 11/12/2024.
//

#include "ConsoleOutputStream.hpp"

void ConsoleOutputStream::writeLine(std::string line) {
    buffer.push_back(line + "\n");
}
void ConsoleOutputStream::flush() {
    for (std::string line : this -> buffer) {
        std::cout << line;
    }
    this->buffer = std::vector<std::string>();
}