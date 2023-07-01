#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> Array(num);
    for (int i = 0; i < num; i++) {
        cin >> Array[i];
    }
    int X, Y;
    cin >> X >> Y;

    int count = 0;
    int count0 = 0;
    int count1 = 0;
    vector<int> count0PrefixSum(num + 1, 0);
    vector<int> count1PrefixSum(num + 1, 0);

    for (int i = 1; i <= num; i++) {
        count0PrefixSum[i] = count0PrefixSum[i - 1] + (Array[i - 1] == 0);
        count1PrefixSum[i] = count1PrefixSum[i - 1] + (Array[i - 1] == 1);
    }

    for (int i = 1; i <= num; i++) {
        for (int j = i; j <= num; j++) {
            count0 = count0PrefixSum[j] - count0PrefixSum[i - 1];
            count1 = count1PrefixSum[j] - count1PrefixSum[i - 1];
            if (count0 > X && count1 > Y) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
