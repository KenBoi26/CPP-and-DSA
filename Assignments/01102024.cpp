#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int k, d;
        cin >> k >> d;

        vector<int> gasStations(k);
        for (int i = 0; i < k; ++i) {
            cin >> gasStations[i];
        }

        gasStations.push_back(0);
        gasStations.push_back(d);

        sort(gasStations.begin(), gasStations.end());

        int maxDistance = 0;
        for (int i = 1; i < gasStations.size(); ++i) {
            maxDistance = max(maxDistance, gasStations[i] - gasStations[i - 1]);
        }

        int minGasTankVolume = maxDistance * 2;
        cout << minGasTankVolume << endl;
    }

    return 0;
}
