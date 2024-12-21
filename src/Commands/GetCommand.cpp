#include "../Commands/GetCommand.hpp"
#include "../Classes/StorageIterator.hpp"
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
static bool isInVector(std::vector<std::string> vec, std::string str) {
    for (const auto& entry : vec) {
        if (entry.compare(str) == 0) {
            return true;
        }
    }
    return false;

}

static int calculateSimilarity(const std::vector<std::string>& userA, const std::vector<std::string>& userB) {
    int commonMovies = 0;
    for (const auto& movie : userA) {
        if (isInVector(userB, movie)) {
            ++commonMovies;
        }
    }
    return commonMovies;
}
static int isLongInteger(const char* str) {
    char* endptr;

    // Use strtol to convert the string to a long integer
    strtol(str, &endptr, 10);

    // Check if there were any non-digit characters after the conversion
    // If endptr points to the null terminator, the entire string is a valid long
    return *endptr == '\0';
}

GetCommand::GetCommand(Storage *storage,
                                   OutputStream *outputStream,
                                   ErrorStream *errorStream, IResponseProtocol* responseProtocol) {
    this->storage = storage;
    this->outputStream = outputStream;
    this->errorStream = errorStream;
    this->responseProtocol = responseProtocol;
}
void GetCommand::execute(std::vector<std::string> arguments) {
    std::string userId = arguments[0];
    std::string movieId = arguments[1];

    // Retrieve user data

    User tmp = User(userId, nullptr);
    std::string* storedUser = storage->retrieve(UserType, &tmp);
    if (storedUser == nullptr) {
        responseProtocol->BadRequest();
        return;
    }

    // we assume that any string can be looked at as userID / MovieID

    User* user = new User(*storedUser);


    const auto& userMovies = user->getMovies();


    // Find similar users who have watched the given movie
    std::unordered_map<std::string, int> similarities; // Map userID -> similarity score
    StorageIterator userIterator = StorageIterator(storage, UserType);
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
        std::string* otherStoredUser = storage->retrieve(UserType, &tmp);
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
                  return   a.second > b.second ||
                         ( a.second == b.second &&
                                  ( isLongInteger(a.first.c_str()) && !isLongInteger(b.first.c_str()) ||
                                          ( isLongInteger(a.first.c_str()) &&
                                            isLongInteger(b.first.c_str()) &&
                                            strtol(a.first.c_str(), nullptr, 10) < strtol(b.first.c_str(), nullptr, 10)
                                          )
                                  )
                         );
              });

    // Output top 10 recommendations
    std::string recommendation = "";
    int count = 0;

    for (const auto& [movie, score] : sortedMovies) {
        recommendation += " " + movie;
        if (++count >= 10) break;
    }

    if (recommendation.empty() == false)
        recommendation = recommendation.substr(1);
    responseProtocol->Ok();
    outputStream->writeLine("");
    outputStream->writeLine(recommendation);
}

void GetCommand::printCommand() {
    outputStream->writeLine("GET [userId] [movieId]");
}
std::string GetCommand::name() {
    return "GET";
}
