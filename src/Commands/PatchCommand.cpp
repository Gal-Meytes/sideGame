//
// Created by Surfer Boy on 11/12/2024.
//

#include "PatchCommand.hpp"
PatchCommand::PatchCommand(Storage* storage, OutputStream *outputStream,
        ErrorStream *errorStream, IResponseProtocol* responseProtocol) {
this->storage = storage;
this->outputStream = outputStream;
this->errorStream = errorStream;
this->responseProtocol = responseProtocol;
}
void PatchCommand::execute(std::vector<std::string> arguments) {
    if (arguments.size() < 2) {
        responseProtocol->BadRequest();
    }

    int userId = std::stoi(arguments[0]);
    std::vector<std::string> movieIds(arguments.begin() + 1, arguments.end());

    std::string key = std::to_string(userId);
    User tmp = User(key, nullptr);
    std::string* userSerialized = (std::string*) storage->retrieve(UserType, &tmp);

    if (userSerialized == nullptr) {
        responseProtocol->NotFound();
        return;
    } else {
        // User exists, update their movie list
        User* user = new User(*userSerialized);
        user->insertMovies(movieIds);
        if (!storage->update(UserType, user)) {
            errorStream->outputError("Error: Failed to update user in storage.\n");
        }
        responseProtocol->NoContent();
    }
}
void PatchCommand::printCommand() {
    outputStream->writeLine("PATCH [userId] [movieIds] ...");
}
std::string PatchCommand::name() {
    return "PATCH";
}