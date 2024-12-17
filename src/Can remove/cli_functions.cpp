#include "AddHandler.hpp"
#include "Storage.h"
#include "User.h"

void add(int userId, std::vector<std::string>& movieIds, Storage& storage) {
    std::string key = std::to_string(userId);
    User tmp = User(key, nullptr);
    std::string* userSerialized = (std::string*) storage.retrieve(UserType, &tmp);

    if (userSerialized == nullptr) {
        // User doesn't exist, create a new one and add to storage
        User* newUser = new User(key, movieIds);
        if (!storage.add(UserType, newUser)) {
            std::cerr << "Error: Failed to add new user to storage.\n";
        }
    } else {
        // User exists, update their movie list
        User* user = new User(*userSerialized);
        user->insertMovies(movieIds);
        if (!storage.update(UserType, user)) {
            std::cerr << "Error: Failed to update user in storage.\n";
        }
    }
}


