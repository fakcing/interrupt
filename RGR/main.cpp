#include <iostream>
#include <string>
#include "scanner.h"

int main() {
    std::string input;
    std::string errorMessage;

    std::cout << "¬вед≥ть р€док: ";
    std::cin >> input;

    if (validateString(input, errorMessage)) {
        std::cout << "\u2713 " << input << " \u2208 L(V)\n";
    }
    else {
        std::cout << "\u2717 " << input << " \u2209 L(V): " << errorMessage << "\n";
    }

    return 0;
}