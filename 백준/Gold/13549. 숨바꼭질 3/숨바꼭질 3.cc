#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    
    vector<int> dist(1e5+1, INT_MAX);
    
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int time = dist[curr];
        if(curr == m){
            cout<<time;
            break;
        }
        
        if(curr*2 <= 1e5 && dist[curr*2] > time){
            dist[curr*2] = time;
            q.push(curr*2);
        }
        if(curr+1 <= 1e5 && dist[curr+1] > time + 1){
            dist[curr+1] = time + 1;
            q.push(curr+1);
        }
        if(curr-1 >= 0 && dist[curr-1] > time + 1){
            dist[curr-1] = time + 1;
            q.push(curr-1);
        }
    }
    
    return 0;
}