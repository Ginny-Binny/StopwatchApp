#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateVolume(const vector<int>& volumes, double temperature) {
    double total_volume = 0;
    for (int volume : volumes) {
        total_volume += pow(volume + temperature, 3);
    }
    return total_volume;
}

int main() {
    int Q;
    cin >> Q;

    const int MAX_ITERATIONS = 10000;  // Maximum number of iterations

    for (int q = 0; q < Q; q++) {
        int N, U;
        cin >> N >> U;

        vector<int> volumes(N);
        for (int i = 0; i < N; i++) {
            cin >> volumes[i];
        }

        double low = 0, high = 1000;
        int iterations = 0;

        while (abs(calculateVolume(volumes, high) - U) > 1e-2 && iterations < MAX_ITERATIONS) {
            double mid = (low + high) / 2;
            double total_volume = calculateVolume(volumes, mid);

            if (total_volume < U) {
                low = mid;
            } else {
                high = mid;
            }

            iterations++;
        }

        cout.precision(2);
        cout << fixed << high << endl;
    }

    return 0;
}

