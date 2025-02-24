//
// Created by Surfer Boy on 19/02/2025.
//

#ifndef MY_PROJECT_EMPTYRESPONSEPROTOCOL_HPP
#define MY_PROJECT_EMPTYRESPONSEPROTOCOL_HPP
#include "../Interfaces/IResponseProtocol.hpp"

class EmptyResponseProtocol : public IResponseProtocol{
public:
    void Ok() {};
    void Created() override {};
    void NoContent() override {};
    void NotFound() override {};
    void BadRequest() override {};
};


#endif //MY_PROJECT_EMPTYRESPONSEPROTOCOL_HPP
