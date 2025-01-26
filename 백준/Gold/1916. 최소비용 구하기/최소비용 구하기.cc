#include <iostream>
#include <vector>
#include <climits>
#include <queue>

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
                pq.push({dist[v], v});
            }
        }
    }
    cout<<ans;
    
    return 0;
}
