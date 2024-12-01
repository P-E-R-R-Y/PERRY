#include <string>
#include <iostream>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string timeConversion(string s) {
    if (s.substr(8, 2) == "PM") {
        if (s.substr(0, 2) != "12") {
          return s.substr(0, 8);
        }
        s = std::to_string(std::stoi(s.substr(0, 2)) + 12) + s.substr(2, 6);
        if (s.substr(0, 2) == "24") {
            s = "00" + s.substr(2, 6);
        }
    }
    if (s.substr(8, 10) == "AM") {
        s = s.substr(0, 8);
        if (s.substr(0, 2) == "12") {
            s = "00" + s.substr(2, 8);
        }
    }
    std::cout << s << std::endl;
    return  s;
}


int main()
{
    string result = timeConversion("12:40:22PM");

    return 0;
}
