#include <iostream>
#include <vector>

void miniMaxSum(std::vector<int> arr) {
    auto min = arr.begin();
    auto max = arr.begin();
    long int mini = 0;
    long int maxi = 0;
    
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        if (*it < *min) {
            min = it;
        }
        if (*it > *max) {
            max = it;
        }
    }
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        if (it != min)
            mini += *it;
        if (it != max)
            maxi += *it;
    }
    std::cout << maxi << " " << mini << std::endl;
}

int main()
{

    std::vector<int> arr = {1, 2, 3, 4, 5};
    miniMaxSum(arr);

    return 0;
}