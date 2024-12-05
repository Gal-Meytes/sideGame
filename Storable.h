//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef PROJECT_IDENTIFIABLE_H
#define PROJECT_IDENTIFIABLE_H
#include "LibraryDependencies.h"

class Storable {
public:
    Storable();
    std::string getIdentity();
    std::string serialize();
};


#endif //PROJECT_IDENTIFIABLE_H
