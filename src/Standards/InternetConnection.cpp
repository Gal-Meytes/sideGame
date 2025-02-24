//
// Created by Surfer Boy on 21/12/2024.
//

#include "InternetConnection.hpp"
InternetConnection::InternetConnection(int clientSocket, ErrorStream* errorStream) : clientSocket(clientSocket), errorStream(errorStream) {}
InternetConnection::~InternetConnection() {
    if (clientSocket != -1)
        close(clientSocket);
}

std::string InternetConnection::readLine() {
    std::string result;
    char buffer [1024];
    bool hasBeenRead = false;
    int bytesRead;
    do {
        bytesRead = read(clientSocket, &buffer, sizeof (buffer));
        if (bytesRead == -1)
            return "invalid";
        if (bytesRead > 0) {
            result.append(buffer, bytesRead);
            hasBeenRead = true;
        }
        if (bytesRead == 0 && hasBeenRead == false) {
            return "invalid";
        }
    } while (bytesRead == sizeof (buffer));
    return result;
}

void InternetConnection::writeLine(std::string message) {
    log.push_back(message + "\n");
}
void InternetConnection::flush() {
    std::string toSend;

    for (std::string & message : log) {
        toSend += message;
    }

    if (write(clientSocket, toSend.c_str(), toSend.size()) < 0) {
        errorStream->outputError("Failed to write to client");
    }
    this->log = std::vector<std::string>();
}
void InternetConnection::outputError(std::string error) {
    std::string toSend = error + "\n";
    if (write(clientSocket, toSend.c_str(), toSend.size()) < 0) {
        errorStream->outputError("Failed to write to client");
    }
}

InputStream *InternetConnection::getInputStream() {return this;}
ErrorStream *InternetConnection::getErrorStream() {return this;}
OutputStream *InternetConnection::getOutputStream() {return this;}