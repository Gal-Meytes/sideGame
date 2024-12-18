#include <gtest/gtest.h>
#include "../Classes/Storage.h"
#include "../Standards/FileStorageDevice.cpp"
#include "../Can remove/RecommendCommand.hpp"
#include "../Commands/HelpCommand.hpp"
#include "../Can remove/AddCommand.hpp"
#include "../Interfaces/StorageDevice.h"
#include <algorithm>
#include <unordered_set>
#include <unordered_map> 
#include <vector>
#include <string>
#include <iostream>
#include "../Classes/User.h"
#include "../Classes/StorageIterator.hpp"

const char* dataPath = "/usr/src/mytest";

// Test for `help` function
TEST(HelpFunctionTest, DisplayHelpMessage) {
    std::string expectedHelpMessage = 
        "  add [userId] [movieIds] ...\n";
        "  recommend [userId] [movieId]\n";
        "  help\n";

    std::string actualHelpMessage = testhelp();
    EXPECT_EQ(actualHelpMessage, expectedHelpMessage);
}

TEST(AddFunctionTest, AddNewUser) {
    StorageDevice* device = new FileStorageDevice(dataPath);
    Storage storage(device);

    // Prepare test data
    std::vector<std::string> movieIds = {"movie1", "movie2"};
    int userId = 1;

    // Call add function
    add(userId, movieIds, storage);

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

    // Prepare test data
    std::vector<std::string> movieIds1 = {"movie1", "movie2"};
    std::vector<std::string> movieIds2 = {"movie3", "movie4"};
    int userId1 = 1;
    int userId2 = 2;

    // Call add function for multiple users
    add(userId1, movieIds1, storage);
    add(userId2, movieIds2, storage);

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

    // Prepare test data
    std::vector<std::string> initialMovieIds = {"movie1", "movie2"};
    std::vector<std::string> updatedMovieIds = {"movie3", "movie4"};
    int userId = 1;

    // Add initial user data
    add(userId, initialMovieIds, storage);

    // Update user data
    add(userId, updatedMovieIds, storage);

    // Validate the user data was updated successfully
    User user("1", nullptr);
    std::string* retrieved = storage.retrieve(UserType, &user);
    ASSERT_NE(retrieved, nullptr);
    // Assuming the storage concatenates movie lists
    ASSERT_TRUE(retrieved->find("movie3") != std::string::npos);
    ASSERT_TRUE(retrieved->find("movie4") != std::string::npos);

    delete device; // Clean up
}