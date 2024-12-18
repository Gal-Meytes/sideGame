//
// Created by Surfer Boy on 11/12/2024.
//

#include "PostCommand.hpp"
AddCommand::PostCommand(Storage* storage, OutputStream *outputStream,
                       ErrorStream *errorStream, IResponseProtocol* responseProtocol) {
    this->storage = storage;
    this->outputStream = outputStream;
    this->errorStream = errorStream;
    this->responseProtocol = responseProtocol;
}
void PostCommand::execute(std::vector<std::string> arguments) {
    if (arguments.size() < 2) {
        responseProtocol->BadRequest();
    }

    int userId = std::stoi(arguments[0]);
    std::vector<std::string> movieIds(arguments.begin() + 1, arguments.end());

    std::string key = std::to_string(userId);
    User tmp = User(key, nullptr);
    std::string* userSerialized = (std::string*) storage->retrieve(UserType, &tmp);

    if (userSerialized == nullptr) {
        // User doesn't exist, create a new one and add to storage
        User* newUser = new User(key, movieIds);
        if (!storage->add(UserType, newUser)) {
            errorStream->outputError("Error: Failed to add new user to storage.\n");
        }
        responseProtocol->Created();
        return;
    }
    responseProtocol->BadRequest();
}
void PostCommand::printCommand() {
    outputStream->writeLine("POST [userId] [movieIds] ...");
}
std::string AddCommand::name() {
    return "POST";
}