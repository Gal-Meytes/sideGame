//
// Created by Surfer Boy on 30/11/2024.
//


#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include "LibraryDependencies.h"
#include "Storable.h"

class User : public Storable {
private:
    std::string userID;
    std::vector<std::string> movieIds;
public:
    virtual ~User() = default;
    User(std::string userID, const std::vector<std::string>& movieIds);
    User::User(std::string serialized_user);
    void insertMovies(std::vector<std::string>& movieIds);
    std::string getIdentity();
    std::string serialize();
    std::vector<std::string> getMovies();
};


#endif //PROJECT_USER_H
