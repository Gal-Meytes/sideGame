//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_CONSOLEIOFACTORY_HPP
#define MY_PROJECT_CONSOLEIOFACTORY_HPP

#include "IIOFactory.hpp"

class ConsoleIOFactory : public IIOFactory {
    virtual class InputStream* InputStream() override;
    virtual class OutputStream* OutputStream() override;
    virtual class ErrorStream* ErrorStream() override;
};


#endif //MY_PROJECT_CONSOLEIOFACTORY_HPP
