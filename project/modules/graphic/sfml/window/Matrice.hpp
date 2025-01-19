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
    T& operator()(int row, int col) { return data[row][col]; }
    const T& operator()(int row, int col) const { return data[row][col]; }

    //operator=
    Matrice<T> operator=(const Matrice<T>& other) {
        if (this != &other) {
            data = other.data;
            rows = other.rows;
            cols = other.cols;
        }
        return *this;
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
    if (a.getCols() != b.getRows()) {
        throw std::invalid_argument("Matrix dimensions must be compatible for multiplication!");
    }

    int rows = a.getRows();
    int cols = b.getCols();
    int commonDim = a.getCols();

    // Create result matrix
    Matrice<T> result(rows, cols);

    // Matrix multiplication logic
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            T sum = T(); // Initialize sum to default value (e.g., 0 for numbers)
            for (int k = 0; k < commonDim; ++k) {
                sum += a(i, k) * b(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}