#include <iostream>
#include <string>
#include "scanner.h"

int main() {
    std::string input;
    std::string errorMessage;

    std::cout << "Ââåä³òü ðÿäîê: ";
    std::cin >> input;

    if (validateString(input, errorMessage)) {
        std::cout << " " << input << " \n";
    }
    else {
        std::cout << " " << input << "  " << errorMessage << "\n";
    }

    return 0;
}
