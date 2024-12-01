#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    std::map<int, float> maps;
    maps[0] = 0;
    maps[1] = 0;
    maps[-1] = 0;
    
    if (arr.size() == 0) {
        for (int i = 0; i < 3;++i)
          std::cout << 0.000000 << std::endl;
    }

    for (auto it = arr.begin(); it != arr.end(); it++) {
      std::cout << *it << std::endl;
        if (*it == 0) {
            maps[0] += 1;
        }
        else if (*it > 0) {
            maps[1] += 1;
        } else {
            maps[-1] += 1;
        }
    }
    std::cout << std::fixed << std::setprecision(6) << (maps[1] / arr.size()) << std::endl;
    std::cout << (maps[0] / arr.size()) << std::endl;
    std::cout << (maps[-1] / arr.size()) << std::endl;
}

int main()
{
    std::vector<int> arr = {-4, 3, -9, 0, 4, 1};
    plusMinus(arr);
    return 0;
}
