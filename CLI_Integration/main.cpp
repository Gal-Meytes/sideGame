#include "Integrator.hpp"

int main() {
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        integrationCommend(input);
    }

    return 0;
}
