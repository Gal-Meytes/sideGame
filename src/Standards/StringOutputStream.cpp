//
// Created by Surfer Boy on 18/02/2025.
//

#include "StringOutputStream.hpp"
void StringOutputStream::writeLine(std::string line) {
    buffer.push_back(line + "\n");
}
void StringOutputStream::flush() {
    for (std::string line : this -> buffer) {
        this->output += line;
    }
    this->buffer = std::vector<std::string>();
}
std::string StringOutputStream::getOutput() {
    flush();
    return this->output;
}