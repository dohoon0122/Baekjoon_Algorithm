#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

void solve() {
    int N, M, W;
    cin >> N >> M >> W;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < M; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({s, e, t});
        edges.push_back({e, s, t});
    }

    for (int i = 0; i < W; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({s, e, -t});
    }
    
    // Johnson
    for (int i = 1; i <= N; i++) {
        edges.push_back({0, i, 0});
    }

    vector<long long> dist(N + 1, INT_MAX);
    dist[0] = 0;

    for (int i = 0; i <= N; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (i == N) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }

    return 0;
}