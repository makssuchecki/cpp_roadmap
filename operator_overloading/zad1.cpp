#include <iostream>

class Vector2D {
public:
    double x, y;

    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }
    Vector2D operator*(double other) const {
        return Vector2D(x * other, y * other);
    }
    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

};

int main() {
    Vector2D a(1, 2);
    Vector2D b(3, 4);

    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * 2 = " << (a * 2) << "\n";
    std::cout << "a == b: " << std::boolalpha << (a == b) << "\n";
    std::cout << "a == a: " << std::boolalpha << (a == a) << "\n";
    return 0;
}