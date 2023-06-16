#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, Q;
        cin >> N >> Q;

        vector<int> A(N);
        map<int, int> frequency;
        long long sum = 0, count = 0;

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            sum += A[i];
            count++;
            frequency[A[i]]++;
        }

        for (int q = 0; q < Q; q++) {
            int query;
            cin >> query;

            if (query == 1) {
                int X;
                cin >> X;
                A.push_back(X);
                sum += X;
                count++;
                frequency[X]++;
            } else if (query == 2) {
                int mean = sum / count;
                cout << mean << endl;
            } else if (query == 3) {
                int mode = A[0];
                int maxFrequency = frequency[A[0]];

                for (int i = 1; i < A.size(); i++) {
                    if (frequency[A[i]] > maxFrequency || (frequency[A[i]] == maxFrequency && A[i] < mode)) {
                        mode = A[i];
                        maxFrequency = frequency[A[i]];
                    }
                }

                cout << mode << endl;
            }
        }
    }

    return 0;
}
