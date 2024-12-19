#include "scanner.h"

bool validateSubstring(const std::string& sub, std::string& errorMessage) {
    if (sub.empty()) {
        errorMessage = "Підрядок пустий.";
        return false;
    }

    if (sub[0] != '$') {
        errorMessage = "Підрядок має починатися із символу '$'.";
        return false;
    }

    for (size_t i = 1; i < sub.size(); ++i) {
        char c = sub[i];
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            errorMessage = "Символ '" + std::string(1, c) + "' неприпустимий. Дозволено тільки '0..9' та 'A..F'.";
            return false;
        }
    }

    return true;
}

bool validateString(const std::string& s, std::string& errorMessage) {
    size_t atPos = s.find('@');
    if (atPos == std::string::npos) {
        errorMessage = "Рядок має містити символ '@', що розділяє підрядки.";
        return false;
    }

    std::string firstSub = s.substr(0, atPos);
    std::string secondSub = s.substr(atPos + 1);

    if (!validateSubstring(firstSub, errorMessage)) {
        errorMessage = "Помилка в першому підрядку: " + errorMessage;
        return false;
    }

    if (!validateSubstring(secondSub, errorMessage)) {
        errorMessage = "Помилка в другому підрядку: " + errorMessage;
        return false;
    }

    return true;
}