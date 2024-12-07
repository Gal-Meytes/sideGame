#ifndef RECOMMEND_HPP
#define RECOMMEND_HPP

#include <unordered_set>
#include <unordered_map> 
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Storage.h"
#include "User.h"

int calculateSimilarity(const std::vector<std::string>& userA, const std::vector<std::string>& userB);

std::string recommend(Storage& storage, const std::vector<std::string>& args);

#endif // RECOMMEND_HPP