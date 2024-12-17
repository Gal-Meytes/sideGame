//
// Created by Surfer Boy on 17/12/2024.
//

#include "StreamHTTPResponseProtocol.hpp"
StreamHTTPResponseProtocol::StreamHTTPResponseProtocol(
        OutputStream *outputStream) {
    this->outputStream = outputStream;
}

void StreamHTTPResponseProtocol::Ok() {
    outputStream->writeLine("200 OK");
}

void StreamHTTPResponseProtocol::Created() {
    outputStream->writeLine("201 Created");
}

void StreamHTTPResponseProtocol::NoContent() {
    outputStream->writeLine("204 No Content");
}

void StreamHTTPResponseProtocol::BadRequest() {
    outputStream->writeLine("400 Bad Request");
}

void StreamHTTPResponseProtocol::NotFound() {
    outputStream->writeLine("404 Not Found");
}
