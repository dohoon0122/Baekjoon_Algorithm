#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin>>N>>M;
    vector<vector<int>> board(N, vector<int>(M));
    vector<vector<int>> ans(N, vector<int>(M, -1));
    
    pair<int, int> start = {0, 0};
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j] == 2){
                start.first = i;
                start.second = j;
            }
            else if(board[i][j] == 0){
                ans[i][j] = 0;
            }
        }
    }
    
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    queue<pair<int, int>> q;
    q.push(start);
    
    
    ans[start.first][start.second] = 0;
    
    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();
        int curr = ans[row][col];
        
        for(auto& [dr, dc]: dir){
            int n_row = row + dr;
            int n_col = col + dc;
            if(0<=n_row && n_row<N && 0<=n_col && n_col<M){
                if(ans[n_row][n_col] == -1){
                    if(board[n_row][n_col] == 1){
                        ans[n_row][n_col] = curr + 1;
                        q.push({n_row, n_col});
                    }
                }
            }
        }
    }
    //cout
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
