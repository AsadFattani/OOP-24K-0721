#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    private:
        double real;
        double imag;

    public:
        Complex (double r = 0, double i = 0) : real(r), imag(i) {}

        Complex operator+(const Complex &complex) {
            return Complex(real + complex.real, imag + complex.imag);
        }

        Complex operator-(const Complex &complex) {
            return Complex(real - complex.real, imag - complex.imag);
        }

        Complex operator*(const Complex &complex) {
            return Complex(real * complex.real - imag * complex.imag, real * complex.imag + imag * complex.real);
        }

        Complex operator/(const Complex &complex) {
            double denominator = complex.real * complex.real + complex.imag * complex.imag;
            return Complex((real * complex.real + imag * complex.imag) / denominator, (imag * complex.real - real * complex.imag) / denominator);
        }

        friend ostream& operator<<(ostream &out, const Complex &complex) {
            if (complex.imag >= 0)
                out << complex.real << " + " << complex.imag << "i";
            else
                out << complex.real << " - " << -complex.imag << "i";
            return out;
        }

        friend double magnitude(const Complex &complex) {
            return sqrt(complex.real * complex.real + complex.imag * complex.imag);
        }
};

int main () {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "Complex Number 1: " << c1 << endl;
    cout << "Complex Number 2: " << c2 << endl;

    cout << "Addition: " << c1 + c2 << endl;
    cout << "Subtraction: " << c1 - c2 << endl;
    cout << "Multiplication: " << c1 * c2 << endl;
    cout << "Division: " << c1 / c2 << endl;

    cout << "Magnitude of Complex Number 1: " << magnitude(c1) << endl;
    cout << "Magnitude of Complex Number 2: " << magnitude(c2) << endl;

    return 0;
}





