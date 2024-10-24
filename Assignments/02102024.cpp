#include <iostream>
#include <vector>
using namespace std;

int playGame(vector<int>& seq) {
    while (seq.size() > 1) {
        int n = seq.size();
        for (int i = 0; i < n - 1; i++) {
            if (seq.size() % 2 == 1) {
                seq[i] = max(seq[i], seq[i + 1]);
            } else {
                seq[i] = min(seq[i], seq[i + 1]);
            }
            seq.erase(seq.begin() + i + 1);
            break;
        }
    }
    return seq[0];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> seq(n);
        for (int i = 0; i < n; i++) {
            cin >> seq[i];
        }

        int result = playGame(seq);
        cout << result << endl;
    }

    return 0;
}
