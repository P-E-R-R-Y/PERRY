#pragma once

#include <cmath>
#include <array>

template <typename T>
class Matrice {
public:
    // Constructor to create a matrix with the given number of rows and columns
    Matrice(int rows, int cols) : data(rows, std::vector<T>(cols)), rows(rows), cols(cols) {}

    // Constructor to initialize the matrix with a 2D vector
    Matrice(const std::vector<std::vector<T>>& grid) : data(grid), rows(grid.size()), cols(grid[0].size()) {}

    // Accessor for matrix elements (row, col)
    T& operator()(int row, int col) {
        return data[row][col];
    }

    //operator=
    Matrice<T> operator=(const Matrice<T>& other) {
        if (this != &other) {
            data = other.data;
            rows = other.rows;
            cols = other.cols;
        }
        return *this;
    }

    std::vector<T> operator[](const int index) const {
        return data[index];
    }

    // Getter for rows and cols
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // Print matrix (for debugging purposes)
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<T>> data;  // 2D vector to store matrix data
    int rows;
    int cols;
};

template <typename T>
Matrice<T> operator*(const Matrice<T>& a, const Matrice<T>& b) {
    int aRows = a.getRows();
    int aCols = a.getCols();
    int bRows = b.getRows();
    int bCols = b.getCols();

    // Ensure matrices are compatible for multiplication
    if (aCols != bRows) {
        throw std::invalid_argument("Matrix dimensions must be compatible for multiplication!");
    }

    // Create a result matrix of size aRows x bCols
    Matrice<T> result(aRows, bCols);

    // Matrix multiplication logic
    for (int i = 0; i < aRows; ++i) {
        for (int j = 0; j < bCols; ++j) {
            T sum = T();  // Initialize to the default value (e.g., 0)
            for (int k = 0; k < aCols; ++k) {
                sum += a[i][k] * b[k][j];
            }
            result(i, j) = sum;
        }
    }

    return result;
}

template <typename T>
Matrice<T> operator*=(Matrice<T>& a, const Matrice<T>& b) {
    a = a * b;
    return a;
}