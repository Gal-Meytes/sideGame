//
// Created by Surfer Boy on 17/12/2024.
//


#include "App.hpp"
#include "iostream"
#include "algorithm"
std::vector<std::string> split(const std::string& str, char delimiter)
{
    std::stringstream ss(str);  // No need for 'std::stringstream ss = ...'
    std::vector<std::string> res;
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        res.push_back(token);
    }

    return res;
}

App::App(std::unordered_map<std::string, ICommand*>* commands, InputStream* istream, OutputStream* outputStream,  IResponseProtocol* responseProtocol) {
    this->commands = commands;
    this->inputStream = istream;
    this->outputStream = outputStream;
    this->responseProtocol = responseProtocol;
}

void App::run() {
    while (true) {
        std::string line = inputStream->readLine();
        if (line == "invalid")
            continue;
        std::vector<std::string> inputArgs = split(line, ' ');

        const std::string badString = "";
        inputArgs.erase(std::remove(inputArgs.begin(), inputArgs.end(), badString), inputArgs.end());

        if (inputArgs.empty())
            break;
        std::string inputCommand = inputArgs[0];
        inputArgs.erase(inputArgs.begin());

        bool validCommandName = false;
        for (const std::pair<std::string,ICommand*>& command : *commands) {
            if (command.first == inputCommand)
            {
                (command.second)->execute(inputArgs);
                validCommandName = true;
                break;
            }
        }
        if (validCommandName == false)
            responseProtocol->BadRequest();
        outputStream->flush();
    }
}
