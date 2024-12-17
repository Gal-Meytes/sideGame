//
// Created by Surfer Boy on 17/12/2024.
//

#ifndef MY_PROJECT_STREAMHTTPRESPONSEPROTOCOL_HPP
#define MY_PROJECT_STREAMHTTPRESPONSEPROTOCOL_HPP
#include "../Interfaces/IResponseProtocol.hpp"
#include "../Interfaces/OutputStream.hpp"
class StreamHTTPResponseProtocol : public IResponseProtocol{
private:
    OutputStream* outputStream;
public:
    explicit StreamHTTPResponseProtocol(OutputStream* outputStream);
    virtual void Ok() override;
    virtual void Created() override;
    virtual void NoContent() override;
    virtual void BadRequest() override;
    virtual void NotFound() override;
};


#endif //MY_PROJECT_STREAMHTTPRESPONSEPROTOCOL_HPP
