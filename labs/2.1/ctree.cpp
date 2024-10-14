#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>  // Для работы с цветом на Windows
#else
#include <unistd.h>  // Для UNIX систем
#endif

using namespace std;

// Функция для установки цвета текста в консоли (Windows и ANSI-совместимые системы)
void setConsoleColor(int colorCode) {
#ifdef _WIN32
    // Для Windows
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
#else
    // Для UNIX (используем ANSI escape codes)
    cout << "\033[" << colorCode << "m";
#endif
}

// Функция для сброса цвета консоли
void resetConsoleColor() {
#ifdef _WIN32
    // Для Windows
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);  // Вернуть стандартный цвет
#else
    // Для UNIX
    cout << "\033[0m";
#endif
}

// Функция для вывода елки с гирляндой, меняющей цвет
void printTreeWithGarland(const vector<string>& tree) {
    // Массив кодов цветов для гирлянды
    vector<int> colors = { 31, 32, 33, 34, 35, 36 }; // ANSI-коды для красного, зеленого, желтого, синего, пурпурного и голубого
#ifdef _WIN32
    // Windows color codes
    vector<int> winColors = { 4, 2, 14, 1, 5, 3 };  // Аналогичные цвета для Windows
#endif

    int colorIndex = 0;

    while (true) {
        // Проходим по строкам елки
        for (const auto& line : tree) {
            for (char c : line) {
                // Если символ гирлянды
                if (c == '*' || c == '+' || c == '#' || c == '@' || c == '&' || c == '%') {
#ifdef _WIN32
                    setConsoleColor(winColors[colorIndex]);  // Для Windows
#else
                    setConsoleColor(colors[colorIndex]);  // Для Unix-подобных систем
#endif
                    cout << c;
                    resetConsoleColor();  // Сброс цвета
                }
                else {
                    cout << c;  // Остальные символы просто печатаем
                }
            }
            cout << endl;  // Переход на новую строку
        }

        // Меняем цвет гирлянды
        colorIndex = (colorIndex + 1) % colors.size();

        // Задержка перед следующим изменением цвета (0.5 секунды)
        this_thread::sleep_for(chrono::milliseconds(500));

        // Очищаем экран для обновления (работает на Windows и Unix)
#ifdef _WIN32
        system("CLS");
#else
        cout << "\033[2J\033[1;1H";
#endif
    }
}

int main() {
    ifstream file("christmas_tree.txt");  // Чтение из файла christmas_tree.txt
    vector<string> tree;

    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Чтение елки из файла
    string line;
    while (getline(file, line)) {
        tree.push_back(line);
    }
    file.close();

    // Вывод елки с гирляндой, меняющей цвет
    printTreeWithGarland(tree);

    return 0;
}
