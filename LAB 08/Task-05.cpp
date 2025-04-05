#include <iostream>
using namespace std;

class Matrix2x2 {
    private:
        int a, b, c, d;

    public:
        Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) : a(a), b(b), c(c), d(d) {}

        Matrix2x2 operator+(const Matrix2x2 &matrix){
            return Matrix2x2(a + matrix.a, b + matrix.b, c + matrix.c, d + matrix.d);
        }

        Matrix2x2 operator-(const Matrix2x2 &matrix){
            return Matrix2x2(a - matrix.a, b - matrix.b, c - matrix.c, d - matrix.d);
        }

        Matrix2x2 operator*(const Matrix2x2 &matrix){
            return Matrix2x2(
                a * matrix.a + b * matrix.c,
                a * matrix.b + b * matrix.d,
                c * matrix.a + d * matrix.c,
                c * matrix.b + d * matrix.d
            );
        }

        friend int determinant(const Matrix2x2 &matrix);

        friend ostream& operator<<(ostream &os, const Matrix2x2 &matrix){
            os << "[" << matrix.a << " " << matrix.b << "]" << endl;
            os << "[" << matrix.c << " " << matrix.d << "]" << endl;
            return os;
        }

        friend class MatrixHelper;
};

int determinant(const Matrix2x2 &matrix){
    return (matrix.a * matrix.d) - (matrix.b * matrix.c);
}

class MatrixHelper {
    public:
        void updateElement(Matrix2x2 &matrix, int row, int col, int value) {
            if (row == 0 && col == 0) matrix.a = value;
            else if (row == 0 && col == 1) matrix.b = value;
            else if (row == 1 && col == 0) matrix.c = value;
            else if (row == 1 && col == 1) matrix.d = value;
            else cout << "Invalid indices!" << endl;
        }
};

int main() {
    Matrix2x2 matrix1(1, 2, 3, 4);
    Matrix2x2 matrix2(5, 6, 7, 8);

    MatrixHelper helper;
    cout << "Matrix 1:" << endl << matrix1;
    cout << "Matrix 2:" << endl << matrix2;

    Matrix2x2 sum = matrix1 + matrix2;
    Matrix2x2 diff = matrix1 - matrix2;
    Matrix2x2 product = matrix1 * matrix2;
    int det = determinant(matrix1);

    cout << "Sum:" << endl << sum;
    cout << "Difference:" << endl << diff;
    cout << "Product:" << endl << product;
    cout << "Determinant of Matrix 1: " << det << endl;

    int row, col, value;
    cout << "Enter row (0 or 1), column (0 or 1), and new value to update Matrix 1: ";
    cin >> row >> col >> value;
    helper.updateElement(matrix1, row, col, value);
    
    cout << "Updated Matrix 1:" << endl << matrix1;

    return 0;
}







