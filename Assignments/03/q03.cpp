#include <iostream>

using namespace std;

template <typename T>
class Matrix {
protected:
    T **matrix;
    unsigned rows, cols;
public:
    Matrix(unsigned rows, unsigned cols) : rows(rows), cols(cols) {
        if (rows != cols) rows = cols;

        matrix = new T *[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new T[cols];
            for (int j = 0; j < cols; j++)
                matrix[i][j] = T();
        }
    }

    ~Matrix<T>() {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
    }

    void set(unsigned row, unsigned col, T value) { matrix[row][col] = value; }
    T get(unsigned row, unsigned col) const { return matrix[row][col]; }

    Matrix<T>& operator + (const Matrix<T>& other) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                matrix[i][j] += other.matrix[i][j];
        }
        return *this;
    }

    Matrix<T>& operator - (const Matrix<T>& other) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                matrix[i][j] -= other.matrix[i][j];
        }
        return *this;
    }

    Matrix<T>& operator * (Matrix<T>& other) {
        T result[rows][cols] = { T() };

        // perform calculation and store in result
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                for (int k = 0; k < rows; ++k)
                    result[i][j] += matrix[i][k] * other.matrix[k][j];

        // set matrix as result
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                matrix[i][j] = result[i][j];

        return *this;
    }

    virtual void display() const = 0;
};

class IntMatrix : public Matrix<int> {
public:
    IntMatrix(unsigned rows, unsigned cols) : Matrix<int>(rows, cols) {}

    void display() const override {
        cout << "Integer Matrix: " << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
};

class DoubleMatrix : public Matrix<double> {
public:
    DoubleMatrix(unsigned rows, unsigned cols) : Matrix<double>(rows, cols) {}

    void display() const override {
        cout << "Double Matrix: " << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    IntMatrix m1(2, 2);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);
    m1.display();

    IntMatrix m2(2, 2);
    m2.set(0, 0, 1);
    m2.set(0, 1, 1);
    m2.set(1, 0, 1);
    m2.set(1, 1, 1);
    m2.display();

    DoubleMatrix m3(2, 2);
    m3.set(0, 0, 1.1f);
    m3.set(0, 1, 2.2f);
    m3.set(1, 0, 3.3f);
    m3.set(1, 1, 4.4f);
    m3.display();

    DoubleMatrix m4(2, 2);
    m4.set(0, 0, 4.f);
    m4.set(0, 1, 2.f);
    m4.set(1, 0, 1.f);
    m4.set(1, 1, 0.5f);
    m4.display();

    (m1 + m2).display();
    (m2 - m1 - m1).display();
    (m3 * m4).display();

    return 0;
}