#include "LibraryDependencies.h"
#include "StorageDevice.h"
#include "FileStorageDevice.cpp"
#include "Storage.h"
#include "Storage.cpp"
#include "User.cpp"
#include "user.h"
using namespace std;

void loadVector(std::vector<std::string>* vector, std::string* array, int size) {
    for(int i = 0; i < size; i++) {
        vector->push_back(array[i]);
    }
}

int main() {
    StorageDevice* device = new FileStorageDevice("/mnt/c/Users/Surfer Boy/OneDrive/Desktop/Study/CS/University/Advanced System Programming/forPhotos");
    Storage storage = Storage(device);
    auto* Movies1 = new std::vector<std::string>();
    auto* Movies2 = new std::vector<std::string>();
    auto* Movies3 = new std::vector<std::string>();
    auto* Movies4 = new std::vector<std::string>();
    auto* Movies5 = new std::vector<std::string>();
    Movies1->push_back("99 ");Movies1->push_back("23 ");Movies1->push_back("45");
    Movies2->push_back("12 ");Movies2->push_back("27 ");Movies2->push_back("99");
    Movies3->push_back("45 ");Movies3->push_back("11 ");Movies3->push_back("45");
    Movies4->push_back("80 ");Movies4->push_back("23 ");Movies4->push_back("23");
    Movies5->push_back("11 ");Movies5->push_back("12 ");Movies5->push_back("13");
    

    User user1 = User ("1", *Movies1);
    User user2 = User ("2", *Movies2);
    User user3 = User ("3", *Movies3);
    User user4 = User ("4", *Movies4);

    storage.add(UserType, &user1);
    storage.add(UserType, &user2);
    storage.add(UserType, &user3);
    storage.add(UserType, &user4);

    std::string* ret = (std::string*) storage.retrieve(UserType, &user4);
    printf("%s\n", ret->c_str());

    ret = (std::string*) storage.retrieve(UserType, &user2);
    printf("%s\n", ret->c_str());

    ret = (std::string*) storage.retrieve(UserType, &user3);
    printf("%s\n", ret->c_str());

    ret = (std::string*) storage.retrieve(UserType, &user1);
    printf("%s\n", ret->c_str());


    user4.insertMovies(*Movies5);
    storage.update(UserType, &user4);
    ret = (std::string*) storage.retrieve(UserType, &user4);
    printf("after change:\n%s\n", ret->c_str());
}



