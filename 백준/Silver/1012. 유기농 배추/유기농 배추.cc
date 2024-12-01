#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int T;
    vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    cin>>T;
    for(int i=0; i<T; i++){
        int M, N, K;
        cin>>M>>N>>K;
        vector<vector<int>> field(M, vector<int>(N, 0));
        for(int j=0; j<K; j++){
            int x, y;
            cin>>x>>y;
            field[x][y] = 1;
        }
        int ans = 0;
        for(int row=0; row<M; row++){
            for(int col=0; col<N; col++){
                if(field[row][col] == 1){
                    ans++;
                    field[row][col] = 2;
                    queue<pair<int, int>> q;
                    q.push({row, col});
                    
                    while(!q.empty()){
                        auto [c_row, c_col] = q.front();
                        q.pop();
                        for(auto [dr, dc]: delta){
                            int n_row, n_col;
                            n_row = c_row+dr;
                            n_col = c_col+dc;
                            if(0<=n_row && n_row<M && 0<=n_col && n_col<N){
                                if(field[n_row][n_col] == 1){
                                    field[n_row][n_col] = 2;
                                    q.push({n_row, n_col});
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}