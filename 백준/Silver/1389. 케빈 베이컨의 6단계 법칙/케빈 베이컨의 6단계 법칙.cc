#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin>>N>>M;
    vector<vector<bool>> adj_arr(N+1, vector<bool>(N+1, false));
    
    for(int i=0; i<M; i++){
        int u, v;
        cin>>u>>v;
        adj_arr[u][v] = true;
        adj_arr[v][u] = true;
    }
    
    vector<vector<int>> dist(N+1, vector<int>(N+1, 501));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) dist[i][j] = 0;
            if(adj_arr[i][j]) dist[i][j] = 1;
        }
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int ans = INT_MAX;
    int ans_idx = 0;
    for(int i=1; i<=N; i++){
        int temp=0;
        for(int j=1; j<=N; j++){
            temp += dist[i][j];
        }
        if(temp < ans){
            ans_idx = i;
            ans = temp;
        }
    }
    cout<<ans_idx;
}