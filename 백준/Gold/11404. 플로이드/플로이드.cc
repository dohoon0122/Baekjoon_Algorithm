#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    
    vector<vector<long long>> dist(n, vector<long long>(n, INT_MAX));
    for(int i=0; i<n;i++){
        dist[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(dist[a-1][b-1] > c) dist[a-1][b-1] = c;
    }
    
     
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j]<INT_MAX) cout<<dist[i][j]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
    return 0;
}