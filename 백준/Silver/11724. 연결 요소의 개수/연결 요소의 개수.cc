#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin>>N>>M;
    
    vector<vector<int>> adj_list(N+1, vector<int>());
    
    for(int i=0; i<M; i++){
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    vector<bool> visited(N+1, false);
    int ans = 0;
    
    stack<int> s;
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            ans++;
            s.push(i);
            visited[i] = true;
            
            while(!s.empty()){
                int u = s.top();
                s.pop();
                for(auto v: adj_list[u]){
                    if(!visited[v]){
                        s.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
}
