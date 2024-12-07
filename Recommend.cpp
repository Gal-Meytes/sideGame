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

/**
 * @brief Calculates the similarity between two users based on shared movies.
 * 
 * This function takes two unordered sets of strings representing the movies watched by two users.
 * It calculates the number of common movies between the two users and returns the similarity score.
 * 
 * @param userA The unordered set of strings representing the movies watched by user A.
 * @param userB The unordered set of strings representing the movies watched by user B.
 */
int calculateSimilarity(const std::vector<std::string>& userA, const std::vector<std::string>& userB) {
    int commonMovies = 0;
    for (const auto& movie : userA) {
        if (std::find(userB.begin(), userB.end(), movie) != userB.end()) {
            ++commonMovies;
        }
    }
    return commonMovies;
}

std::string recommend(Storage& storage, const std::vector<std::string>& args) {
   

    std::string userId = args[0];
    std::string movieId = args[1];

    // Retrieve user data
    Storable* storableUser = storage.retrieve(UserType, userId);
   

    User* user = dynamic_cast<User*>(storableUser);
    

    const auto& userMovies = user->getMovies();


    // Find similar users who have watched the given movie
    std::unordered_map<std::string, int> similarities; // Map userID -> similarity score
    for (auto it = storage.begin(); it != storage.end(); ++it) {
        const auto& [serialized_other_user, _other_user] = *it;
        User other_user = User(serialized_other_user);
        if (other_user.getIdentity() != userId && std::find(other_user.getMovies().begin(), other_user.getMovies().end(), movieId) != other_user.getMovies().end()) {
            similarities[other_user.getIdentity()] = calculateSimilarity(userMovies, other_user.getMovies());
        }
    }

    // Score other movies based on similar users
    std::unordered_map<std::string, int> movieScores; // Map movieID -> relevance score
    for (const auto& [otherUserId, similarity] : similarities) {
        Storable* otherStorableUser = storage.retrieve(UserType, otherUserId);
        User* otherUser = dynamic_cast<User*>(otherStorableUser);
        if (otherUser == nullptr) {
            continue;
        }

        const auto& otherUserMovies = otherUser->getMovies();
        for (const auto& movie : otherUserMovies) {
            if (std::find(userMovies.begin(), userMovies.end(), movie) == userMovies.end()) { // Exclude movies already watched
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
    return recommendation;
}


