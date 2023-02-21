
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
    int n = a.length();
    int m = b.length();
    int max_repeat = (m - 1) / n + 1;

    string repeated_a = "";

    for (int i = 1; i <= max_repeat; i++) {
        repeated_a += a;

        if (repeated_a.find(b) != string::npos) {
            return i;
        }
    }

    repeated_a += a;
    if (repeated_a.find(b) != string::npos) {
        return max_repeat + 1;
    }

    return -1;
}


};