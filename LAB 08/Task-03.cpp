#include <iostream>
using namespace std;

class Vector2D {
    private:
        double x, y;

    public:
        Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

        Vector2D operator+(const Vector2D &v) {
            return Vector2D(x + v.x, y + v.y);
        }

        Vector2D operator-(const Vector2D &v) {
            return Vector2D(x - v.x, y - v.y);
        }

        Vector2D operator*(double scalar) {
            return Vector2D(x * scalar, y * scalar);
        }

        friend double dotProduct(const Vector2D &v1, const Vector2D &v2);
        
        friend ostream& operator<<(ostream &os, const Vector2D &v) {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }
};

double dotProduct(const Vector2D &v1, const Vector2D &v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}

int main() {
    Vector2D v1(3, 4), v2(1, 2);
    
    Vector2D sum = v1 + v2;
    Vector2D diff = v1 - v2;
    Vector2D scaled = v1 * 2.0;
    double dot = dotProduct(v1, v2);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Scaled: " << scaled << endl;
    cout << "Dot Product: " << dot << endl;

    return 0;
}






