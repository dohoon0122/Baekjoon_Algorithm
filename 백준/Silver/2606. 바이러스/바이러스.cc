#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int V, E;
    cin>>V>>E;
    
    vector<vector<int>> adj_list(V+1, vector<int>());
    
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    stack<int> s;
    s.push(1);
    vector<bool> visited(V+1, false);
    
    int ans = -1;
    while(!s.empty()){
        int curr =s.top();
        s.pop();
        
        if(visited[curr]) continue;
        else visited[curr] = true;
        
        ans++;
        for(auto v: adj_list[curr]){
            s.push(v);
        }
    }
    
    cout<<ans;
}