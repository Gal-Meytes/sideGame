//
// Created by Surfer Boy on 30/11/2024.
//


#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include "LibraryDependencies.h"
#include "Identifier.h"

class User :Identifier {
private:
    int userID;
    std::vector<std::string>& movieIds;
public:
    User(int userID, const std::vector<std::string>& movieIds);
    void insertMovies(std::vector<std::string>& movieIds);
    std::string Identify();
};


#endif //PROJECT_USER_H
