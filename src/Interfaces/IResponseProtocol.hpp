//
// Created by Surfer Boy on 17/12/2024.
//

#ifndef MY_PROJECT_IRESULTPROTOCOL_HPP
#define MY_PROJECT_IRESULTPROTOCOL_HPP
#include "iostream"
#include "OutputStream.hpp"
class IResponseProtocol {
public:
    virtual void Ok() = 0;
    virtual void Created() = 0;
    virtual void NoContent() = 0;
    virtual void BadRequest() = 0;
    virtual void NotFound() = 0;
};


#endif //MY_PROJECT_IRESULTPROTOCOL_HPP
