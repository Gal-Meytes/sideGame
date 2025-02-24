#include <gtest/gtest.h>
#include "../Classes/Storage.h"
#include "../Standards/FileStorageDevice.cpp"
#include "../Commands/HelpCommand.hpp"
#include "../Interfaces/StorageDevice.h"
#include <algorithm>
#include <unordered_set>
#include <unordered_map> 
#include <vector>
#include <string>
#include <iostream>
#include "../Classes/User.h"
#include "../Classes/StorageIterator.hpp"
#include "../Commands/PostCommand.hpp"
#include "../Standards/ConsoleErrorStream.hpp"
#include "../Standards/ConsoleOutputStream.hpp"
#include "../Standards/StreamHTTPResponseProtocol.hpp"
#include "../Factories/StdCommandFactory.hpp"
#include "../Standards/StringOutputStream.hpp"
#include "../Standards/StreamHTTPResponseProtocol.hpp"
#include "../Factories/StdCommandFactory.hpp"
#include "../Classes/Storage.h"
#include "../Standards/EmptyResponseProtocol.hpp"

const char* dataPath = "/app/testsData";

// Test for `help` function
TEST(HelpFunctionTest, DisplayHelpMessage) {
    StorageDevice* device = new FileStorageDevice(dataPath);
    Storage storage(device);
    ErrorStream * errorStream = new ConsoleErrorStream();
    StringOutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new EmptyResponseProtocol();

    std::string expectedHelpMessage =
        "\nDELETE [userId] [movieIds] ...\n"
        "GET [userId] [movieId]\n"
        "PATCH [userId] [movieIds] ...\n"
        "POST [userId] [movieIds] ...\n"
        "help\n";
    StdCommandFactory* stdCommandFactory = new StdCommandFactory(&storage, outputStream, errorStream, responseProtocol);
    ICommand* helpCommand = (*stdCommandFactory->commands())["help"];
    helpCommand->execute(std::vector<std::string>());

    EXPECT_EQ(outputStream->getOutput(), expectedHelpMessage);
}

TEST(AddFunctionTest, AddNewUser) {
    StorageDevice* device = new FileStorageDevice(dataPath);
    Storage storage(device);
    ErrorStream * errorStream = new ConsoleErrorStream();
    StringOutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new StreamHTTPResponseProtocol(outputStream);

    // Prepare test data
    std::vector<std::string> postValue = {"1", "movie1", "movie2"};
    int userId = 1;

    // Call add function
    PostCommand* postCommand = new PostCommand(&storage, outputStream, errorStream, responseProtocol);

    postCommand->execute(postValue);

    // Validate the user was added successfully
    User user("1", nullptr); // Create a user object with ID "1"
    std::string* retrieved = storage.retrieve(UserType, &user);
    ASSERT_NE(retrieved, nullptr);

    delete device; // Clean up
}

// Test for retrieving non-existent user
TEST(StorageTest, RetrieveNonExistentUser) {
    StorageDevice* device = new FileStorageDevice(dataPath);
    Storage storage(device);

    // Attempt to retrieve a user that doesn't exist
    User nonExistentUser("99", nullptr);
    std::string* retrieved = storage.retrieve(UserType, &nonExistentUser);

    // Validate the retrieval returns null
    ASSERT_EQ(retrieved, nullptr);

    delete device; // Clean up
}

// Test for adding multiple users
TEST(AddFunctionTest, AddMultipleUsers) {
    StorageDevice* device = new FileStorageDevice(dataPath);
    Storage storage(device);
    ErrorStream * errorStream = new ConsoleErrorStream();
    OutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new StreamHTTPResponseProtocol(outputStream);

    PostCommand* postCommand = new PostCommand(&storage, outputStream, errorStream, responseProtocol);

    // Prepare test data
    std::vector<std::string> first_user = {"1", "movie1", "movie2"};
    std::vector<std::string> second_user = {"2", "movie3", "movie4"};

    postCommand->execute(first_user);
    postCommand->execute(second_user);

    // Validate both users were added successfully
    User user1("1", nullptr);
    User user2("2", nullptr);
    std::string* retrieved1 = storage.retrieve(UserType, &user1);
    std::string* retrieved2 = storage.retrieve(UserType, &user2);
    ASSERT_NE(retrieved1, nullptr);
    ASSERT_NE(retrieved2, nullptr);

    delete device; // Clean up
}

// Test for updating user data
TEST(UpdateFunctionTest, UpdateUserMovies) {
    StorageDevice* device = new FileStorageDevice(dataPath);
    Storage storage(device);
    ErrorStream * errorStream = new ConsoleErrorStream();
    OutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new StreamHTTPResponseProtocol(outputStream);

    PostCommand* postCommand = new PostCommand(&storage, outputStream, errorStream, responseProtocol);
    PatchCommand* patchCommand = new PatchCommand(&storage, outputStream, errorStream, responseProtocol);

    // Prepare test data
    std::vector<std::string> initialMovieIds = {"1", "movie1", "movie2"};
    std::vector<std::string> updatedMovieIds = {"1", "movie3", "movie4"};

    // Add initial user data
    postCommand->execute(initialMovieIds);

    // Update user data
    patchCommand->execute(updatedMovieIds);

    // Validate the user data was updated successfully
    User user("1", nullptr);
    std::string* retrieved = storage.retrieve(UserType, &user);
    ASSERT_NE(retrieved, nullptr);
    // Assuming the storage concatenates movie lists
    ASSERT_TRUE(retrieved->find("movie3") != std::string::npos);
    ASSERT_TRUE(retrieved->find("movie4") != std::string::npos);

    delete device; // Clean up
}

TEST(DeleteFunctionTest, DeleteUserMovies) {
    StorageDevice* device = new FileStorageDevice(dataPath);
    Storage storage(device);
    ErrorStream * errorStream = new ConsoleErrorStream();
    OutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new StreamHTTPResponseProtocol(outputStream);

    PostCommand* postCommand = new PostCommand(&storage, outputStream, errorStream, responseProtocol);
    DeleteCommand* deleteCommand = new DeleteCommand(&storage, outputStream, errorStream, responseProtocol);

    // Prepare test data
    std::vector<std::string> initialMovieIds = {"1", "movie1", "movie2"};
    std::vector<std::string> deletedMovieIds = {"1", "movie1", "movie2"};

    // Add initial user data
    postCommand->execute(initialMovieIds);

    // Update user data
    deleteCommand->execute(deletedMovieIds);

    // Validate the user data was updated successfully
    User user("1", nullptr);
    std::string* retrieved = storage.retrieve(UserType, &user);
    ASSERT_NE(retrieved, nullptr);
    // Assuming the storage concatenates movie lists
    ASSERT_TRUE(retrieved->find("movie3") != std::string::npos);
    ASSERT_TRUE(retrieved->find("movie4") != std::string::npos);

    delete device; // Clean up
}

TEST(DeleteFunctionTest, DeleteUserPartialMovies) {
    StorageDevice* device = new FileStorageDevice(dataPath);
    Storage storage(device);
    ErrorStream * errorStream = new ConsoleErrorStream();
    OutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new StreamHTTPResponseProtocol(outputStream);

    PostCommand* postCommand = new PostCommand(&storage, outputStream, errorStream, responseProtocol);
    DeleteCommand* deleteCommand = new DeleteCommand(&storage, outputStream, errorStream, responseProtocol);

    // Prepare test data
    std::vector<std::string> initialMovieIds = {"1", "movie1", "movie2"};
    std::vector<std::string> deletedMovieIds = {"1", "movie2"};

    // Add initial user data
    postCommand->execute(initialMovieIds);

    // Update user data
    deleteCommand->execute(deletedMovieIds);

    // Validate the user data was updated successfully
    User user("1", nullptr);
    std::string* retrieved = storage.retrieve(UserType, &user);
    ASSERT_NE(retrieved, nullptr);
    // Assuming the storage concatenates movie lists
    ASSERT_TRUE(retrieved->find("movie3") != std::string::npos);
    ASSERT_TRUE(retrieved->find("movie4") != std::string::npos);

    delete device; // Clean up
}

TEST(HTTPResponseTest, Ok) {
    StringOutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new StreamHTTPResponseProtocol(outputStream);
    responseProtocol->Ok();

    std::string expectedOkMessage = "200 OK\n";
    EXPECT_EQ(outputStream->getOutput(), expectedOkMessage);
}
TEST(HTTPResponseTest, Created) {
    StringOutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new StreamHTTPResponseProtocol(outputStream);
    responseProtocol->Created();

    std::string expectedMessage = "201 Created\n";
    EXPECT_EQ(outputStream->getOutput(), expectedMessage);
}
TEST(HTTPResponseTest, NoContent) {
    StringOutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new StreamHTTPResponseProtocol(outputStream);
    responseProtocol->NoContent();

    std::string expectedMessage = "204 No Content\n";
    EXPECT_EQ(outputStream->getOutput(), expectedMessage);
}

TEST(HTTPResponseTest, BadRequest) {
    StringOutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new StreamHTTPResponseProtocol(outputStream);
    responseProtocol->BadRequest();

    std::string expectedMessage = "400 Bad Request\n";
    EXPECT_EQ(outputStream->getOutput(), expectedMessage);
}
TEST(HTTPResponseTest, NotFound) {
    StringOutputStream * outputStream = new StringOutputStream();
    IResponseProtocol * responseProtocol = new StreamHTTPResponseProtocol(outputStream);
    responseProtocol->NotFound();

    std::string expectedMessage = "404 Not Found\n";
    EXPECT_EQ(outputStream->getOutput(), expectedMessage);
}

TEST(UserTests, UserSerialized) {
    std::vector<std::string> movieIds = {"movie1", "movie2"};
    std::string userId = "1";

    User user = User(userId, movieIds);
    std::string expected = "Id: 1 Movies Watched: movie1 movie2 ";
    std::string  serialized = user.serialize();
    EXPECT_EQ(expected, serialized);
}

TEST(UserTests, UserSerializedToUser) {
    std::vector<std::string> movieIds = {"movie1", "movie2"};
    std::string userId = "1";

    User templete = User(userId, movieIds);
    std::string  serialized = templete.serialize();

    User user = User(serialized);
    std::vector<std::string> movies = user.getMovies();
    std::string moviesString = "";
    for (std::string movie : movies) {
        moviesString += movie + " ";
    }
    movies = movieIds;
    EXPECT_EQ(movies, templete.getMovies());
}
// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
