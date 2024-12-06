//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef PROJECT_IDENTIFIABLE_H
#define PROJECT_IDENTIFIABLE_H
#include "LibraryDependencies.h"

class Storable {
public:
    Storable() = default;

    virtual std::string getIdentity() = 0;
    virtual std::string serialize() = 0;
};


#endif //PROJECT_IDENTIFIABLE_H
