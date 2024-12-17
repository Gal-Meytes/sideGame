#include "ReccomendHandler.hpp"
#include "Recommend.hpp"
/**
 * @brief Handles the 'reccomend' command by delegating to the reccomend function.
 * 
 * This function expects exactly two arguments: a user ID and a movie ID. If the number
 * of arguments is not equal to 2, it prints an error message and returns.
 * 
 * @param args A vector of strings containing the arguments for the 'reccomend' command.
 *             The first argument should be the user ID and the second argument should be the movie ID.
 */


void handleReccomend(Storage& storage, const std::vector<std::string>& args) {
    if (args.size() == 2) {
        std::string* recommendation = recommend(storage, args);
        if (recommendation == nullptr)
            return;
    std::cout << *recommendation << std::endl;
    }
}


/**
 * @brief Tests the recommendation function with a custom sorting logic.
 * 
 * This function behaves like the original `recommend`, but allows a custom sort logic for test purposes.
 * 
 * @param storage Reference to the storage instance.
 * @param args Arguments for the recommendation, where args[0] is the user ID and args[1] is the movie ID.
 * @param sortLogic Custom sorting logic for testing, defaulting to the standard sorting logic.
 * @return std::string* Pointer to the recommended movie(s) string.
 */
std::string* RecommendTest(
    Storage& storage, 
    const std::vector<std::string>& args,
    std::function<bool(const std::pair<std::string, int>&, const std::pair<std::string, int>&)> sortLogic
) {
    if (args.size() < 2) return nullptr;

    std::string userId = args[0];
    std::string movieId = args[1];

    // Retrieve user data
    User tmp(userId, nullptr);
    std::string* storedUser = storage.retrieve(UserType, &tmp);
    if (!storedUser) return nullptr;

    User user(*storedUser);
    const auto& userMovies = user.getMovies();

    // Find similar users who have watched the given movie
    std::unordered_map<std::string, int> similarities;
    StorageIterator userIterator(&storage, UserType);
    std::string* serializedOtherUser = userIterator.getNext();
    while (serializedOtherUser) {
        User otherUser(*serializedOtherUser);
        if (otherUser.getIdentity() != userId && 
            std::find(otherUser.getMovies().begin(), otherUser.getMovies().end(), movieId) != otherUser.getMovies().end()) {
            similarities[otherUser.getIdentity()] = calculateSimilarity(userMovies, otherUser.getMovies());
        }
        serializedOtherUser = userIterator.getNext();
    }

    // Score other movies based on similar users
    std::unordered_map<std::string, int> movieScores;
    for (const auto& [otherUserId, similarity] : similarities) {
        User tmp(otherUserId, nullptr);
        std::string* otherStoredUser = storage.retrieve(UserType, &tmp);
        if (!otherStoredUser) continue;

        User otherUser(*otherStoredUser);
        for (const auto& movie : otherUser.getMovies()) {
            if (movie != movieId && 
                std::find(userMovies.begin(), userMovies.end(), movie) == userMovies.end()) {
                movieScores[movie] += similarity;
            }
        }
    }

    // Apply custom or default sorting logic
    std::vector<std::pair<std::string, int>> sortedMovies(movieScores.begin(), movieScores.end());
    if (!sortLogic) {
        sortLogic = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
    }
    std::sort(sortedMovies.begin(), sortedMovies.end(), sortLogic);

    // Build the recommendation string
    std::string recommendation;
    int count = 0;
    for (const auto& [movie, score] : sortedMovies) {
        recommendation += " " + movie;
        if (++count >= 10) break;
    }

    if (!recommendation.empty()) recommendation = recommendation.substr(1);
    return new std::string(recommendation);
}

