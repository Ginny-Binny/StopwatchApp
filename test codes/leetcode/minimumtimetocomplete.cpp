
#include <vector>
#include <algorithm>

using namespace std;

int minTime(vector<int>& time, int totalTrips) {
    int n = time.size();
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + (r - l) / 2;
        long long trips = 0;
        for (int i = 0; i < n; i++) {
            trips += (mid / time[i]);
            if (trips >= totalTrips) break;
        }
        if (trips >= totalTrips) r = mid;
        else l = mid + 1;
    }
    return l;
}
