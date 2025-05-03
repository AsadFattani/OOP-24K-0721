#include <iostream>
#include <stdexcept>
#include <sstream>

class DimensionMismatchException : public std::exception {
    std::string message;
public:
    DimensionMismatchException(int rowsA, int colsA, int rowsB, int colsB) {
        std::ostringstream oss;
        oss << "DimensionMismatchException: Cannot add matrices of dimensions (" 
            << rowsA << "x" << colsA << ") and (" << rowsB << "x" << colsB << ")!";
        message = oss.str();
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class Matrix {
    T** data;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols]();
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void setElement(int row, int col, T value) {
        data[row][col] = value;
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        A.setElement(0, 0, 1);
        A.setElement(0, 1, 2);
        A.setElement(1, 0, 3);
        A.setElement(1, 1, 4);

        B.setElement(0, 0, 5);
        B.setElement(0, 1, 6);
        B.setElement(0, 2, 7);
        B.setElement(1, 0, 8);
        B.setElement(1, 1, 9);
        B.setElement(1, 2, 10);
        B.setElement(2, 0, 11);
        B.setElement(2, 1, 12);
        B.setElement(2, 2, 13);

        Matrix<int> C = A + B;
        C.print();
    } catch (const DimensionMismatchException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
