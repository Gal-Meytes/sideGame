//
// Created by Surfer Boy on 11/12/2024.
//

#include "DeleteCommand.hpp"
DeleteCommand::DeleteCommand(Storage* storage, OutputStream *outputStream,
                       ErrorStream *errorStream, IResponseProtocol* responseProtocol) {
    this->storage = storage;
    this->outputStream = outputStream;
    this->errorStream = errorStream;
    this->responseProtocol = responseProtocol;
}
void DeleteCommand::execute(std::vector<std::string> arguments) {
    if (arguments.size() < 2) {
        responseProtocol->BadRequest();
        return;
    }

    int userId = std::stoi(arguments[0]);
    std::vector<std::string> movieIds(arguments.begin() + 1, arguments.end());

    std::string key = std::to_string(userId);
    User tmp = User(key, nullptr);
    std::string* userSerialized = (std::string*) storage->retrieve(UserType, &tmp);

    if (userSerialized == nullptr) {
        responseProtocol->NotFound();
        return;
    }
    // User exists, update their movie list
    User user (*userSerialized);

    for (std::string movieId : movieIds) {
        if (user.hasWatchedMovie(movieId) == false) {
            responseProtocol->NotFound();
            return;
        }
    }

    for (std::string movieId : movieIds) {
        if (user.hasWatchedMovie(movieId) == true) {
            user.deleteMovie(movieId);
        }
    }

    if (!storage->update(UserType, &user)) {
        errorStream->outputError("Error: Failed to update user data in storage.\n");
    }
    responseProtocol->NoContent();
}
void DeleteCommand::printCommand() {
    outputStream->writeLine("DELETE [userId] [movieIds] ...");
}
std::string DeleteCommand::name() {
    return "DELETE";
}