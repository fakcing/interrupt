#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>  // ��� ������ � ������ �� Windows
#else
#include <unistd.h>  // ��� UNIX ������
#endif

using namespace std;

// ������� ��� ��������� ����� ������ � ������� (Windows � ANSI-����������� �������)
void setConsoleColor(int colorCode) {
#ifdef _WIN32
    // ��� Windows
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
#else
    // ��� UNIX (���������� ANSI escape codes)
    cout << "\033[" << colorCode << "m";
#endif
}

// ������� ��� ������ ����� �������
void resetConsoleColor() {
#ifdef _WIN32
    // ��� Windows
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);  // ������� ����������� ����
#else
    // ��� UNIX
    cout << "\033[0m";
#endif
}

// ������� ��� ������ ���� � ���������, �������� ����
void printTreeWithGarland(const vector<string>& tree) {
    // ������ ����� ������ ��� ��������
    vector<int> colors = { 31, 32, 33, 34, 35, 36 }; // ANSI-���� ��� ��������, ��������, �������, ������, ���������� � ��������
#ifdef _WIN32
    // Windows color codes
    vector<int> winColors = { 4, 2, 14, 1, 5, 3 };  // ����������� ����� ��� Windows
#endif

    int colorIndex = 0;

    while (true) {
        // �������� �� ������� ����
        for (const auto& line : tree) {
            for (char c : line) {
                // ���� ������ ��������
                if (c == '*' || c == '+' || c == '#' || c == '@' || c == '&' || c == '%') {
#ifdef _WIN32
                    setConsoleColor(winColors[colorIndex]);  // ��� Windows
#else
                    setConsoleColor(colors[colorIndex]);  // ��� Unix-�������� ������
#endif
                    cout << c;
                    resetConsoleColor();  // ����� �����
                }
                else {
                    cout << c;  // ��������� ������� ������ ��������
                }
            }
            cout << endl;  // ������� �� ����� ������
        }

        // ������ ���� ��������
        colorIndex = (colorIndex + 1) % colors.size();

        // �������� ����� ��������� ���������� ����� (0.5 �������)
        this_thread::sleep_for(chrono::milliseconds(500));

        // ������� ����� ��� ���������� (�������� �� Windows � Unix)
#ifdef _WIN32
        system("CLS");
#else
        cout << "\033[2J\033[1;1H";
#endif
    }
}

int main() {
    ifstream file("christmas_tree.txt");  // ������ �� ����� christmas_tree.txt
    vector<string> tree;

    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // ������ ���� �� �����
    string line;
    while (getline(file, line)) {
        tree.push_back(line);
    }
    file.close();

    // ����� ���� � ���������, �������� ����
    printTreeWithGarland(tree);

    return 0;
}
