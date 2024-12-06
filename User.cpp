//
// Created by Surfer Boy on 30/11/2024.
//

#include "User.h"
User::User(std::string userID, const std::vector<std::string>& movieIds) {
    this->userID = userID;
    this->movieIds = movieIds;
}
void User::insertMovies(std::vector<std::string> &movieIds) {
    //assumes instance movie vector is initialized
    for (std::string movie : movieIds) {
        this->movieIds.push_back(movie);
    }
}
std::string User::serialize() {
    std::string retString = "";
    retString += "Id: " + std::string(this->userID) + " ";
    retString += "Movies Watched: ";
    for (std::string movieId : this->movieIds) {
        retString += movieId;
        retString +=" ";
    }
    return retString;
}
std::string User::getIdentity() {
    return std::string(userID);
}