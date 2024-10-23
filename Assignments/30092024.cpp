#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<char, int> freqCounter;
    string word;
    cin >> word;

    for (auto i : word) {
        freqCounter[i]++;
    }
    
    while (!freqCounter.empty()) {
        auto maxElem = freqCounter.begin();
        for (auto it = freqCounter.begin(); it != freqCounter.end(); ++it) {
            if (it->second > maxElem->second) {
                maxElem = it;
            }
        }

        for (int j = 0; j < maxElem->second; ++j) {
            cout << maxElem->first;
        }

        freqCounter.erase(maxElem);
    }

    return 0;
}
