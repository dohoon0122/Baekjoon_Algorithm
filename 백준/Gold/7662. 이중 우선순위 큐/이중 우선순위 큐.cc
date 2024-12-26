#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        priority_queue<pair<int, int>> maxH;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minH;
        unordered_map<int, bool> valid;
        int idx = 0;

        while (N--) {
            char order;
            int a;
            cin >> order >> a;

            if (order == 'I') {
                maxH.push({a, idx});
                minH.push({a, idx});
                valid[idx] = true;
                idx++;
            } else if (order == 'D') {
                if (a == 1) {
                    while (!maxH.empty() && !valid[maxH.top().second]) {
                        maxH.pop();
                    }
                    if (!maxH.empty()) {
                        valid[maxH.top().second] = false;
                        maxH.pop();
                    }
                } else {
                    while (!minH.empty() && !valid[minH.top().second]) {
                        minH.pop();
                    }
                    if (!minH.empty()) {
                        valid[minH.top().second] = false;
                        minH.pop();
                    }
                }
            }
        }

        while (!maxH.empty() && !valid[maxH.top().second]) {
            maxH.pop();
        }
        while (!minH.empty() && !valid[minH.top().second]) {
            minH.pop();
        }

        if (maxH.empty() || minH.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << maxH.top().first << " " << minH.top().first << "\n";
        }
    }

    return 0;
}