#include <iostream>
#include <cmath>

class Rectangle {
private:
    double x1, y1, x2, y2;

public:
    Rectangle() : x1(0), y1(0), x2(1), y2(1) {}
    Rectangle(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    Rectangle(const Rectangle& other) : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2) {}
    ~Rectangle() {}

    double getArea() const { return std::abs(x2 - x1) * std::abs(y2 - y1); }
    double getPerimeter() const { return 2 * (std::abs(x2 - x1) + std::abs(y2 - y1)); }

    double getX1() const { return x1; }
    double getY1() const { return y1; }
    double getX2() const { return x2; }
    double getY2() const { return y2; }
};

int main() {
    Rectangle rect1;
    Rectangle rect2(2, 3, 6, 7);
    Rectangle rect3 = rect2;

    std::cout << "Rectangle 1: Area = " << rect1.getArea() << ", Perimeter = " << rect1.getPerimeter() << "\n";
    std::cout << "Rectangle 2: Area = " << rect2.getArea() << ", Perimeter = " << rect2.getPerimeter() << "\n";
    std::cout << "Rectangle 3 (Copy of 2): Area = " << rect3.getArea() << ", Perimeter = " << rect3.getPerimeter() << "\n";

    return 0;
}
