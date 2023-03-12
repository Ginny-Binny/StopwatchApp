#include <iostream>
#include <string>
using namespace std;

string compress_string(string s) {
    int n = s.length();
    string compressed;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            count++;
        } else {
            compressed += s[i-1] + to_string(count);
            count = 1;
        }
    }
    compressed += s[n-1] + to_string(count);
    if (compressed.length() >= n) {
        return s;
    } else {
        return compressed;
    }
}

int main() {
    string s;
    cin >> s;
    cout << compress_string(s) << endl;
    return 0;
}