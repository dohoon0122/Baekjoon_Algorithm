#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin>>n>>m>>x;
    
    vector<int> dist_go(n, INT_MAX);
    vector<int> dist_rt(n, INT_MAX);
    dist_go[x-1] = 0;
    dist_rt[x-1] = 0;
    
    vector<vector<pair<int, int>>> adj_list_r(n);
    vector<vector<pair<int, int>>> adj_list_g(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj_list_r[u-1].push_back({v-1, w});
        adj_list_g[v-1].push_back({u-1, w});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq_g;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq_r;
    
    pq_r.push({0, x-1});
    pq_g.push({0, x-1});
    
    while(!pq_r.empty()){
        auto [dist, idx] = pq_r.top();
        pq_r.pop();
        for(auto [v, w]: adj_list_r[idx]){
            if(dist_rt[v] > dist+w){
                dist_rt[v] = dist + w;
                pq_r.push({dist+w, v});
            }
        }
    }
    while(!pq_g.empty()){
        auto [dist, idx] = pq_g.top();
        pq_g.pop();
        for(auto [v, w]: adj_list_g[idx]){
            if(dist_go[v] > dist+w){
                dist_go[v] = dist + w;
                pq_g.push({dist+w, v});
            }
        }
    }
    
    int max_time =0;
    for(int i=0; i<n; i++){
        int round_dist = dist_go[i] + dist_rt[i];
        if(round_dist>max_time) max_time = round_dist;
    }
    
    cout<<max_time;
    
    return 0;
}