#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    vector<string> apt(N);
    for(int i=0; i<N; i++){
        cin>>apt[i];        
    }
    
    vector<int> ans;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    stack<pair<int, int>> st;
        
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(apt[i][j] == '0') continue;
            if(visited[i][j]) continue;
            
            st.push({i, j});
            visited[i][j] = true;
            int home = 1;
            
            while(!st.empty()){
                auto [row, col] = st.top();
                st.pop();
                for(auto [dr, dc]: dir){
                    int n_row, n_col;
                    n_row = row + dr;
                    n_col = col + dc;
                    if(0<=n_row && n_row<N && 0<=n_col && n_col<N && !visited[n_row][n_col] && apt[n_row][n_col] == '1'){
                        st.push({n_row, n_col});
                        visited[n_row][n_col] = true;
                        home++;
                    }
                }
            }
            ans.push_back(home);
        }
    }
    
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(int h: ans){
        cout<<h<<"\n";
    }
}

