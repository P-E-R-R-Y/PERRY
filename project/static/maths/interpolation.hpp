#include <vector>
#include <array>

template <int k>
class Interpolate {
    public:
      static inline double cubic(double factor, double start, double end) {
          return start + factor * factor * (3.0 - 2.0 * factor) * (end - start);
      }

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