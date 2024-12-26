#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(vector<string>& board, int N, int row, int col, vector<vector<bool>>& visited, int& cnt, bool cb){
    if(!visited[row][col]){
        cnt++;
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        char color = board[row][col];
        
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            for(auto [dr, dc]: dir){
                int n_r = row + dr;
                int n_c = col + dc;
                
                if(0<=n_r && n_r<N && 0<=n_c && n_c<N && !visited[n_r][n_c]){
                    if((!cb && color == board[n_r][n_c]) ||
                      (cb && ((color == 'B' && board[n_r][n_c] == 'B') || (color != 'B' && board[n_r][n_c] != 'B' )))
                      )
                    {
                        q.push({n_r, n_c});
                        visited[n_r][n_c] = true;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<string> board(N);
    for(int i=0; i < N; i++){
        cin>>board[i];
    }
    
    vector<vector<bool>> visited(N, vector(N, false));
    vector<vector<bool>> cb_visited(N, vector(N, false));
    int ans = 0;
    int cb_ans = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            bfs(board, N, i, j, visited, ans, false);
            bfs(board, N, i, j, cb_visited, cb_ans, true);
        }
    }
    cout<<ans<<" "<<cb_ans;

    return 0;
}