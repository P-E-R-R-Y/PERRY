
template <int w, int h>
class Matrix {
public:
    Matrix(int rows, int cols) : m_rows(rows), m_cols(cols) {
        m_data = new double[m_rows * m_cols];
    }

    Matrix(const Matrix& other) : m_rows(other.m_rows), m_cols(other.m_cols) {
        m_data = new double[m_rows * m_cols];
        std::copy(other.m_data, other.m_data + m_rows * m_cols, m_data);
    }

    ~Matrix() {
        delete[] m_data;
    }

    Matrix& operator=(const Matrix& other) const {
        if (this != &other) {
            delete[] m_data;
            m_rows = other.m_rows;
            m_cols = other.m_cols;
            m_data = new double[m_rows * m_cols];
            std::copy(other.m_data, other.m_data + m_rows * m_cols, m_data);
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(m_rows, m_cols);
        for (int i = 0; i < m_rows * m_cols; i++) {
            result.m_data[i] = m_data[i] + other.m_data[i];
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(m_rows, m_cols);
        for (int i = 0; i < m_rows * m_cols; i++) {
            result.m_data[i] = m_data[i] - other.m_data[i];
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(m_rows, other.m_cols);
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < other.m_cols; j++) {
                result(i, j) = 0;
                for (int k = 0; k < m_cols; k++) {
                    result(i, j) += m_data[i * m_cols + k] * other.m_data[k * other.m_cols + j];
                }
            }
        }
        return result;
    }

    Matrix operator/(const Matrix& other) const {
        Matrix result(m_rows, other.m_cols);
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < other.m_cols; j++) {
                result(i, j) = 0;
                for (int k = 0; k < m_cols; k++) {
                    result(i, j) += m_data[i * m_cols + k] / other.m_data[k * other.m_cols + j];
                }
            }
        }
        return result;
    }

    Matrix operator*(double scalar) const {
        Matrix result(m_rows, m_cols);
        for (int i = 0; i < m_rows * m_cols; i++) {
            result.m_data[i] = m_data[i] * scalar;
        }
        return result;
    }

    Matrix operator/(double scalar) const {
        Matrix result(m_rows, m_cols);
        for (int i = 0; i < m_rows * m_cols; i++) {
            result.m_data[i] = m_data[i] / scalar;
        }
        return result;
    }

    void operator+=(Matrix& other) {
        for (int i = 0; i < m_rows * m_cols; i++) {
            m_data[i] += other.m_data[i];
        }
        return *this;
    }

    void operator-=(Matrix& other) {
        for (int i = 0; i < m_rows * m_cols; i++) {
            m_data[i] -= other.m_data[i];
        }
        return *this;
    }

    void operator*=(Matrix& other) {
        Matrix result(m_rows, other.m_cols);
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < other.m_cols; j++) {
                result(i, j) = 0;
                for (int k = 0; k < m_cols; k++) {
                    result(i, j) += m_data[i * m_cols + k] * other.m_data[k * other.m_cols + j];
                }
            }
        }
        return result;
    }

    void operator/=(Matrix& other) {
        Matrix result(m_rows, other.m_cols);
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < other.m_cols; j++) {
                result(i, j) = 0;
                for (int k = 0; k < m_cols; k++) {
                    result(i, j) += m_data[i * m_cols + k] / other.m_data[k * other.m_cols + j];
                }
            }
        }
        return result;
    }

    void operator*=(double scalar) {
        for (int i = 0; i < m_rows * m_cols; i++) {
            m_data[i] *= scalar;
        }
        return *this;
    }

    void operator/=(double scalar) {
        for (int i = 0; i < m_rows * m_cols; i++) {
            m_data[i] /= scalar;
        }
        return *this;
    }

    Matrix transpose() const {
        Matrix result(m_cols, m_rows);
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                result(j, i) = m_data[i * m_cols + j];
            }
        }
        return result;
    }

    Matrix inverse() const {
        Matrix result(m_rows, m_cols);
        double det = determinant();
        if (det == 0) {
            return result;
        }
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                result(j, i) = cofactor(i, j) / det;
            }
        }
        return result;
    }

    double determinant() const {
        if (m_rows != m_cols) {
            return 0;
        }
        if (m_rows == 2) {
            return m_data[0] * m_data[3] - m_data[1] * m_data[2];
        }
        double det = 0;
        for (int i = 0; i < m_cols; i++) {
            det += m_data[i] * cofactor(0, i);
        }
        return det;
    }

    double trace() const {
        if (m_rows != m_cols) {
            return 0;
        }
        double tr = 0;
        for (int i = 0; i < m_rows; i++) {
            tr += m_data[i * m_cols + i];
        }
        return tr;
    }

    double& operator()(int row, int col) {
        return m_data[row * m_cols + col];
    }

    double operator()(int row, int col) const {
        return m_data[row * m_cols + col];
    }

    int rows() const {
        return m_rows;
    }

    int cols() const {
        return m_cols;
    }

    void print() const {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                std::cout << m_data[i * m_cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int m_rows;
    int m_cols;
    double* m_data;
};