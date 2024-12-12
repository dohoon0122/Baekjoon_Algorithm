#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin>>N>>M;
    vector<vector<char>> table(N, vector<char>(M));
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>table[i][j];
            if(table[i][j] == 'I'){
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int person = 0;
    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();
        if(table[row][col] == 'P') person++;
        for(auto [dr, dc]: dir){
            int n_row = row + dr;
            int n_col = col + dc;
            if(0<=n_row && n_row<N && 0<=n_col && n_col<M &&
               visited[n_row][n_col] == false &&
               table[n_row][n_col] != 'X'){
                q.push({n_row, n_col});
                visited[n_row][n_col] = true;
            }
        }
    }
    if(person!=0) cout<<person;
    else cout<<"TT";
}
