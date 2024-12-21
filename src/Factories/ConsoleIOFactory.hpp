//
// Created by Surfer Boy on 11/12/2024.
//

#ifndef MY_PROJECT_CONSOLEIOFACTORY_HPP
#define MY_PROJECT_CONSOLEIOFACTORY_HPP

#include "Abstract Factories/IIOFactory.hpp"

class ConsoleIOFactory : public IIOFactory {
public:
     InputStream* fabricateInputStream() override;
     OutputStream* fabricateOutputStream() override;
     ErrorStream* fabricateErrorStream() override;
};


#endif //MY_PROJECT_CONSOLEIOFACTORY_HPP
