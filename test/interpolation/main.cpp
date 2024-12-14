#include <vector>
#include <tuple>
#include <array>
#include <iostream>
#include <iomanip>

template <int k>
class Interpolate {
    public:
      //
      static inline double linear(double factor, double start, double end) {
          return start + factor * (end - start);          
      }

      static inline std::array<double, k> linear(double factor, std::vector<std::array<double, k>> vec) {
        std::array<std::vector<double>, k> result;
        std::array<double, k> result_array;

        for (size_t j = 0; j < k; j++) {
            for (size_t i = 0; i < vec.size(); i++) {
                result[j].push_back(vec[i][j]);
            }
        }

        while (result[0].size() > 1) {
            std::array<std::vector<double>, k> temp_result;

            // Interpolate between adjacent vectors
            for (size_t i = 0; i < k; i++) {
                for (size_t j = 0; j < result[i].size() - 1; j++) {
                    temp_result[i].push_back(linear(factor, result[i][j], result[i][j + 1]));
                }
            }

            result = temp_result;
        }

        for (int i = 0; i < k; i++) {
            result_array[i] = result[i][0];
        }
        return result_array;
      }
};

int main() {
  const int LENGTH = 2;
  std::vector<std::array<double, LENGTH>> vec = {
    {0, 10},
    {0, 0},
    {10, 0},
    {10, -10},
  };

  std::array<double, LENGTH> result = {0, 0};
  for (double i = 0; i <= 1; i += 0.1) {
    result = Interpolate<LENGTH>::linear(i, vec);
    for (int j = 0; j < LENGTH; j++) {
      std::cout << std::defaultfloat << std::setprecision(5) << std::round(result[j] * 100000) / 100000 << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}