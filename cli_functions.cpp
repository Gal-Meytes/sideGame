#include "AddHandler.hpp"
#include "Storage.h"
#include "User.h"

void add(const int userId, std::vector<std::string>& movieIds, Storage storage) {
    User* user = (User *) storage.retrieve(UserType, userId);
    if (user == NULL) {
        User* newUser = new User(userId, movieIds);
        storage.add(UserType, newUser);
        return;
    }
    user->insertMovies(movieIds);
    storage.update(UserType, user);
}