//
// Created by Surfer Boy on 23/12/2024.
//

#include "InternetConnectionFactory.hpp"

InternetConnectionFactory::InternetConnectionFactory(int port,
                                                     ErrorStream *errorStream) : port(port), fabricationErrorStream(errorStream) {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket < 0) {
            fabricationErrorStream->outputError("Cannot create socket");
            return;
        }
        int opt = 1;
        if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
            fabricationErrorStream->outputError("Cannot set socket option SO_REUSEADDR");
            close(serverSocket);
            return;
        }

        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = INADDR_ANY;
        sin.sin_port = htons(this->port);

        if (bind(serverSocket, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
            fabricationErrorStream->outputError("Cannot bind socket");
            close(serverSocket);
            serverSocket = -1;
            return;
        }

        if (listen(serverSocket, 50) < 0) {
            fabricationErrorStream->outputError("Cannot listen on socket");
            close(serverSocket);
            serverSocket = -1;
        }
}
IConnection *InternetConnectionFactory::fabricateIConnection() {
    if (serverSocket == -1)
        return nullptr;
    struct sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen);
    if (clientSocket < 0) {
        fabricationErrorStream->outputError("Failed to accept connection");
    }
    return new InternetConnection(clientSocket, fabricationErrorStream);
}