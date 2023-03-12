#include <iostream>
using namespace std;

void printComplexStarPattern(int n) {
    // printing upper triangle
    for (int i = 1; i <= n; i++) {
        // printing spaces
        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }
        // printing stars
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // printing lower triangle
    for (int i = n-1; i >= 1; i--) {
        // printing spaces
        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }
        // printing stars
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}


int main() {
    int n;
    cin >> n;

    printComplexStarPattern(n);

    return 0;
}