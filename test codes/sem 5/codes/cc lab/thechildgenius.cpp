#include <iostream>
using namespace std;

pair<int, int> calculateApples(int totalApples, int giaExtra) {
    int maddie = (totalApples - giaExtra) / 2;
    int gia = maddie + giaExtra;
    return make_pair(maddie, gia);
}

int main() {
    int totalApples, giaExtra;
    cout << "Enter the total number of apples: ";
    cin >> totalApples;
    cout << "Enter the number of extra apples that Gia has: ";
    cin >> giaExtra;

    pair<int, int> result = calculateApples(totalApples, giaExtra);

    cout << "Maddie has " << result.first << " apples and Gia has " << result.second << " apples." << endl;

    return 0;
}


#include <iostream>
#include <iterator>
#include <string>
// Uncomment below line to send network request if needed.
// #include <curl/curl.h>
std::string your_code_goes_here(std::string input) {
    // Use this function to return the solution.
    return input;
}

int main() {
    std::istreambuf_iterator<char> begin(std::cin), end;
    std::string input(begin, end);

    std::string output = your_code_goes_here(input);
    std::cout << output << std::endl;
    return 0;
}