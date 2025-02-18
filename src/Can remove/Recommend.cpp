/**
 * @file Recommend.cpp
 * @brief Movie recommendation system.
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 */

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Recommend.hpp"
#include "StorageIterator.hpp"

/**
 * @brief Calculates the similarity between two users based on shared movies.
 * 
 * This function takes two unordered sets of strings representing the movies watched by two users.
 * It calculates the number of common movies between the two users and returns the similarity score.
 * 
 * @param userA The unordered set of strings representing the movies watched by user A.
 * @param userB The unordered set of strings representing the movies watched by user B.
 */

bool isInVector(std::vector<std::string> vec, std::string str) {
    for (const auto& entry : vec) {
        if (entry.compare(str) == 0) {
            return true;
        }
    }
    return false;

}

int calculateSimilarity(const std::vector<std::string>& userA, const std::vector<std::string>& userB) {
    int commonMovies = 0;
    for (const auto& movie : userA) {
        if (isInVector(userB, movie)) {
            ++commonMovies;
        }
    }
    return commonMovies;
}

std::string* recommend(Storage& storage, const std::vector<std::string>& args) {


    std::string userId = args[0];
    std::string movieId = args[1];

    // Retrieve user data

    User tmp = User(userId, nullptr);
    std::string* storedUser = storage.retrieve(UserType, &tmp);
    if (storedUser == nullptr)
        return nullptr;

    User* user = new User(*storedUser);


    const auto& userMovies = user->getMovies();


    // Find similar users who have watched the given movie
    std::unordered_map<std::string, int> similarities; // Map userID -> similarity score
    StorageIterator userIterator = StorageIterator(&storage, UserType);
    std::string* serialized_other_user = userIterator.getNext();
    while (serialized_other_user) {
        User other_user = User(*serialized_other_user);
        if (other_user.getIdentity() != userId &&  isInVector(other_user.getMovies(), movieId)) {
            similarities[other_user.getIdentity()] = calculateSimilarity(userMovies, other_user.getMovies());
        }
        serialized_other_user = userIterator.getNext();
    }

    // Score other movies based on similar users
    std::unordered_map<std::string, int> movieScores; // Map movieID -> relevance score
    for (const auto& [otherUserId, similarity] : similarities) {
        User tmp = User(otherUserId, nullptr);
        std::string* otherStoredUser = storage.retrieve(UserType, &tmp);
        if (otherStoredUser == nullptr) {
            continue;
        }
        User* otherUser = new User(*otherStoredUser);

        const auto& otherUserMovies = otherUser->getMovies();
        for (const auto& movie : otherUserMovies) {
            if (movie.compare(movieId) == 0) {
                continue;
            }
            if (!isInVector(userMovies, movie)) { // Exclude movies already watched
                movieScores[movie] += similarity;
            }
        }
    }

    // Sort movies by relevance
    std::vector<std::pair<std::string, int>> sortedMovies(movieScores.begin(), movieScores.end());
    std::sort(sortedMovies.begin(), sortedMovies.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second || (a.second == b.second && a.first < b.first);
              });

    // Output top 10 recommendations
    std::string recommendation = "";
    int count = 0;
    for (const auto& [movie, score] : sortedMovies) {
        recommendation += " " + movie;
        if (++count >= 10) break;
    }
    recommendation = recommendation.substr(1);
    std::string* returnedRecommendation = new std::string(recommendation);
    return returnedRecommendation;
}