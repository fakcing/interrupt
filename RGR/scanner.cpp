#include "scanner.h"

bool validateSubstring(const std::string& sub, std::string& errorMessage) {
    if (sub.empty()) {
        errorMessage = "ϳ������ ������.";
        return false;
    }

    if (sub[0] != '$') {
        errorMessage = "ϳ������ �� ���������� �� ������� '$'.";
        return false;
    }

    for (size_t i = 1; i < sub.size(); ++i) {
        char c = sub[i];
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            errorMessage = "������ '" + std::string(1, c) + "' �������������. ��������� ����� '0..9' �� 'A..F'.";
            return false;
        }
    }

    return true;
}

bool validateString(const std::string& s, std::string& errorMessage) {
    size_t atPos = s.find('@');
    if (atPos == std::string::npos) {
        errorMessage = "����� �� ������ ������ '@', �� ������� �������.";
        return false;
    }

    std::string firstSub = s.substr(0, atPos);
    std::string secondSub = s.substr(atPos + 1);

    if (!validateSubstring(firstSub, errorMessage)) {
        errorMessage = "������� � ������� �������: " + errorMessage;
        return false;
    }

    if (!validateSubstring(secondSub, errorMessage)) {
        errorMessage = "������� � ������� �������: " + errorMessage;
        return false;
    }

    return true;
}