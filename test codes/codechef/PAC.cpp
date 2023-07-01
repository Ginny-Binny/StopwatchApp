#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countPointsInsideCircle(vector<pair<int, int>>& points, int radius) {
    int maxCount = 0;

    for (int i = 0; i < points.size(); i++) {
        int currentCount = 0;

        for (int j = 0; j < points.size(); j++) {
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            int distanceSq = dx * dx + dy * dy;

            if (distanceSq <= radius * radius) {
                currentCount++;
            }
        }

        maxCount = max(maxCount, currentCount);
    }

    return maxCount;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, radius;
        cin >> n >> radius;

        vector<pair<int, int>> points(n);

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points[i] = make_pair(x, y);
        }

        int maxPointsInsideCircle = countPointsInsideCircle(points, radius);
        cout << maxPointsInsideCircle << endl;
    }

    return 0;
}
