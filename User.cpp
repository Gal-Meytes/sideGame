//
// Created by Surfer Boy on 30/11/2024.
//
#include <sstream>
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

// Deserialize a User object from a string
User::User(std::string serialized_user) {
    std::istringstream iss(serialized_user);
    std::string token;
    std::vector<std::string> tokens;
    
    // Split the serialized_user string into tokens
    while (std::getline(iss, token, ' ')) {
        tokens.push_back(token);
    }
    
    // Extract the user ID from the tokens
    std::string userID = tokens[1];
    
    // Extract the movie IDs from the tokens
    std::vector<std::string> movieIds;
    for (size_t i = 4; i < tokens.size(); i++) {
        movieIds.push_back(tokens[i]);
    }
    
    // Create the new User object
    this->userID = userID;
    this->movieIds = movieIds;
}

std::vector<std::string> User::getMovies() {
    return movieIds;
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