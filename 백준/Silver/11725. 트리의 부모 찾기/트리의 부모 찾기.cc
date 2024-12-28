#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    
    vector<vector<int>> adj_list(N+1, vector<int>());
    
    for(int i=0; i<N; i++){
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    vector<int> ans(N+1, -1);
    
    
    stack<int> s;
    s.push(1);
    ans[1] = 0;
    
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        for(auto next: adj_list[curr]){
            if(ans[next] != -1) continue;
            ans[next] = curr;
            s.push(next);
        }
    }
    
    for(int i=2; i<=N; i++){
        cout<<ans[i]<<"\n";
    }
    
    
    return 0;
}