#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin>>M>>N;
    vector<vector<int>> tmt(N, vector<int>(M, 0));
    queue<pair<int, int>> q;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int curr;
            cin>>curr;
            tmt[i][j] = curr;
            if(curr == 1){
                q.push({i, j});
            }
        }
    }
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();
        int curr = tmt[row][col];
        for(auto [dr, dc]: dir){
            int n_row = row + dr;
            int n_col = col + dc;
            if(0 <= n_row && n_row < N && 0 <= n_col && n_col < M &&
              tmt[n_row][n_col] == 0){
                tmt[n_row][n_col] = curr + 1;
                q.push({n_row, n_col});
            }
        }
    }   
    int ans = 0;
    bool all_mature = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(tmt[i][j] != 0) ans = max(ans, tmt[i][j]);
            else{
                all_mature = false;
                break;
            }
        }
        if(!all_mature) break;
    }

    if(all_mature) cout<<ans-1;
    else cout<<-1;
}