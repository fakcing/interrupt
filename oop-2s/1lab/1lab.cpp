#include <iostream>
#include <cmath>

class Rectangle {
private:
    double x1, y1, x2, y2;

public:
    Rectangle(double x1, double y1, double x2, double y2) 
        : x1(x1), y1(y1), x2(x2), y2(y2) {}

    double getArea() const {
        return std::abs(x2 - x1) * std::abs(y2 - y1);
    }

    double getPerimeter() const {
        return 2 * (std::abs(x2 - x1) + std::abs(y2 - y1));
    }
};

int main() {
    Rectangle rect(1, 1, 5, 4);
    std::cout << "Area: " << rect.getArea() << "\n";
    std::cout << "Perimeter: " << rect.getPerimeter() << "\n";
    return 0;
}