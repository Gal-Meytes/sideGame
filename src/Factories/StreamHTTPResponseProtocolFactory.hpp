//
// Created by Surfer Boy on 17/12/2024.
//

#ifndef MY_PROJECT_STREAMHTTPRESPONSEPROTOCOLFACTORY_HPP
#define MY_PROJECT_STREAMHTTPRESPONSEPROTOCOLFACTORY_HPP
#include "IResponseProtocolFactory.hpp"
#include "../Interfaces/OutputStream.hpp"
#include "../Standards/StreamHTTPResponseProtocol.hpp"
class StreamHTTPResponseProtocolFactory : public IResponseProtocolFactory{
private:
    OutputStream* outputStream;
public:
    StreamHTTPResponseProtocolFactory(OutputStream* inputStream);
    virtual IResponseProtocol* fabricateResponseProtocol();
};


#endif //MY_PROJECT_STREAMHTTPRESPONSEPROTOCOLFACTORY_HPP
