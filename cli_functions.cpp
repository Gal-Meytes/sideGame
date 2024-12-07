#include "AddHandler.hpp"
#include "Storage.h"
#include "User.h"

void add(int userId, std::vector<std::string>& movieIds, Storage& storage) {
    std::string key = std::to_string(userId);
    std::string *user_serialized = storage.retrieve(UserType, key);
    User* user = user_serialized == nullptr? (User *)nullptr : new User(*user_serialized);
    if (user == nullptr) {
        // User doesn't exist, create a new one and add to storage
        User* newUser = new User(key, movieIds);
        if (!storage.add(UserType, newUser)) {
            std::cerr << "Error: Failed to add new user to storage.\n";
        }
    } else {
        // User exists, update their movie list
        user->insertMovies(movieIds);
        if (!storage.update(UserType, user)) {
            std::cerr << "Error: Failed to update user in storage.\n";
        }
    }
}


