//
// Created by Surfer Boy on 17/12/2024.
//

#ifndef MY_PROJECT_IRESPONSEPROTOCOLFACTORY_HPP
#define MY_PROJECT_IRESPONSEPROTOCOLFACTORY_HPP
#include "../Interfaces/IResponseProtocol.hpp"

class IResponseProtocolFactory {
public:
    virtual IResponseProtocol* fabricateResponseProtocol() = 0;
};


#endif //MY_PROJECT_IRESPONSEPROTOCOLFACTORY_HPP
