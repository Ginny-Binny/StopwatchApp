#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long sum = 0, x;
    while (n--) {
        cin >> x;
        sum += x;
    }
    cout << sum << endl;
    return 0;
}
