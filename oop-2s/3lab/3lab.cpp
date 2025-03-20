#include <iostream>
#include <cmath>

class Vector {
private:
    double x, y;

public:
    Vector() : x(0), y(0) {}
    Vector(double x, double y) : x(x), y(y) {}
    Vector(const Vector& other) : x(other.x), y(other.y) {}

    double length() const {
        return std::sqrt(x * x + y * y);
    }

    double getX() const { return x; }
    double getY() const { return y; }

    Vector operator*(double scalar) const {
        return Vector(x * scalar, y * scalar);
    }

    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y);
    }

    void print() const {
        std::cout << "Vector(" << x << ", " << y << ") Length: " << length() << std::endl;
    }
};

int main() {
    Vector V1, V2(3, 4), V3 = V2;
    V3 = V3 * 2;
    V1 = V3 - V2;

    std::cout << "V1: "; V1.print();
    std::cout << "V2: "; V2.print();
    std::cout << "V3: "; V3.print();

    return 0;
}
