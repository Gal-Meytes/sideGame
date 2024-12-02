#include "Integrator.hpp"

int main() {
    std::string input;

    while (true) {
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        integrationCommend(input);
    }

    return 0;
}
