#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <windows.h>

void clearScreen() {
    system("cls");
}

void setConsoleColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

int getRandomColor() {
    int colors[] = { 4, 6, 1, 5, 9 };
    return colors[rand() % 5];
}

void generateTriangle(int height, int maxWidth, std::ofstream& outputFile) {
    const char patternChars[] = { '@', '#', '$', '%', '&', '+' };

    for (int row = 1; row <= height; ++row) {
        for (int space = 0; space < maxWidth - row; ++space) {
            outputFile << " ";
            std::cout << " ";
        }

        for (int star = 0; star < 2 * row - 1; ++star) {
            char decoration;

            if (rand() % 6 == 0) {
                decoration = patternChars[rand() % 6];
                setConsoleColor(getRandomColor());
            }
            else {
                decoration = '*';
                setConsoleColor(2);
            }

            outputFile << decoration;
            std::cout << decoration;
        }

        outputFile << std::endl;
        std::cout << std::endl;
    }
}

void generateTrunk(int trunkHeight, int maxWidth, std::ofstream& outputFile) {
    int trunkWidth = 3;

    for (int row = 0; row < trunkHeight; ++row) {
        for (int space = 0; space < (maxWidth - trunkWidth) / 2; ++space) {
            outputFile << " ";
            std::cout << " ";
        }

        for (int col = 0; col < trunkWidth; ++col) {
            outputFile << "*";
            setConsoleColor(2);
            std::cout << "*";
        }

        outputFile << std::endl;
        std::cout << std::endl;
    }
}

void buildTree(int numberOfSections, std::ofstream& outputFile) {
    int treeWidth = numberOfSections + 2;

    for (int section = 1; section <= numberOfSections; ++section) {
        generateTriangle(section + 1, treeWidth, outputFile);
    }

    int trunkHeight = numberOfSections / 2;
    generateTrunk(trunkHeight, treeWidth * 2 - 1, outputFile);
}

void animateTreeDisplay(int numberOfSections, int frameDelay = 1000) {
    std::ofstream outputFile("tree.txt", std::ios::app);

    while (true) {
        clearScreen();

        buildTree(numberOfSections, outputFile);
        outputFile << "\n\n";
        outputFile.flush();

        std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay));
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numberOfLevels;
    std::cout << "enter the number of tree levels: ";
    std::cin >> numberOfLevels;

    int delayBetweenFrames = 1000;

    animateTreeDisplay(numberOfLevels, delayBetweenFrames);

    return 0;
}