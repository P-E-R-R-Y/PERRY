/**
 * @file Matrice.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup SFML
 * @{
 * @addtogroup sfml_extra extra
 * @{
 */

#pragma once

#include <cmath>
#include <array>

template <typename T>
class Matrice {
public:

    /**
     * @brief Construct a new Matrice object
     * 
     * @param rows 
     * @param cols 
     */
    Matrice(int rows, int cols) : data(rows, std::vector<T>(cols)), rows(rows), cols(cols) {}

    /**
     * @brief Construct a new Matrice object
     * 
     * @param grid 
     */
    Matrice(const std::vector<std::vector<T>>& grid) : data(grid), rows(grid.size()), cols(grid[0].size()) {}

    /**
     * @brief get the value of the matrix at the given row and column
     * 
     * @param row 
     * @param col 
     * @return T& 
     */
    T& operator()(int row, int col) { return data[row][col]; }

    /**
     * @brief get the unmutable value of the matrix at the given row and column
     * 
     * @param row 
     * @param col 
     * @return const T& 
     */
    const T& operator()(int row, int col) const { return data[row][col]; }

    /**
     * @brief copy constructor
     * 
     * @param other 
     * @return Matrice<T> 
     */
    Matrice<T> operator=(const Matrice<T>& other) {
        if (this != &other) {
            data = other.data;
            rows = other.rows;
            cols = other.cols;
        }
        return *this;
    }

    /**
     * @brief Get the Rows object
     * 
     * @return int 
     */
    int getRows() const { return rows; }

    /**
     * @brief Get the Cols object
     * 
     * @return int 
     */
    int getCols() const { return cols; }

    /**
     * @brief Print the matrix
     */
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

/**
 * @brief Define the multiplication operator for matrix multiplication
 * 
 * @tparam T 
 * @param a 
 * @param b 
 * @return Matrice<T> 
 */
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