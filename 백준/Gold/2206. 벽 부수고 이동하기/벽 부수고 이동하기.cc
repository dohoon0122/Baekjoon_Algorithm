#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }

    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, 1e7)));

    queue<vector<int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();

        int row = cur[0], col = cur[1], wall = cur[2];

        for (auto [dr, dc] : dir) {
            int n_row = row + dr;
            int n_col = col + dc;

            if (0 <= n_row && n_row < n && 0 <= n_col && n_col < m) {
                if (board[n_row][n_col] == 0) {
                    if (dist[n_row][n_col][wall] > dist[row][col][wall] + 1) {
                        dist[n_row][n_col][wall] = dist[row][col][wall] + 1;
                        q.push({n_row, n_col, wall});
                    }
                }
                else {
                    if (wall == 0 && dist[n_row][n_col][1] > dist[row][col][wall] + 1) {
                        dist[n_row][n_col][1] = dist[row][col][wall] + 1;
                        q.push({n_row, n_col, 1});
                    }
                }
            }
        }
    }

    int res1 = dist[n - 1][m - 1][0];
    int res2 = dist[n - 1][m - 1][1];
    int result = min(res1, res2);

    cout << (result >= 1e7 ? -1 : result) << "\n";

    return 0;
}
