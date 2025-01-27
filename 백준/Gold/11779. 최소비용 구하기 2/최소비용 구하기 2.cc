#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, a, b;
    cin>>n;
    cin>>m;
    vector<vector<pair<int, int>>> adj_list(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj_list[u-1].push_back({v-1, w});
    }
    
    cin>>a>>b;
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[a-1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, a-1});
    int ans = 0;
    while(!pq.empty()){
        auto [d, idx] = pq.top();
        if(idx == b-1){
            ans = d;
            break;
        }
        pq.pop();
        if(dist[idx] < d) continue;
        
        for(auto [v, w]: adj_list[idx]){
            if(dist[v] > dist[idx] + w){
                dist[v] = dist[idx] + w;
                parent[v] = idx;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout<<ans<<"\n";
    
    stack<int> path;
    for(int i=b-1; i!=-1; i=parent[i]){
        path.push(i+1);
    }
    
    cout<<path.size()<<"\n";
    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }
    
    return 0;
}
