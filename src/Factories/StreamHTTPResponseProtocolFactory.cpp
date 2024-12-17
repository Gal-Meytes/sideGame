//
// Created by Surfer Boy on 17/12/2024.
//

#include "StreamHTTPResponseProtocolFactory.hpp"
StreamHTTPResponseProtocolFactory::StreamHTTPResponseProtocolFactory (OutputStream *outputStream) {
    this->outputStream = outputStream;
}

IResponseProtocol * StreamHTTPResponseProtocolFactory::fabricateResponseProtocol() {
    return new StreamHTTPResponseProtocol(this->outputStream);
}