#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    cin.ignore();
    vector<vector<pair<int, int>>> tree(n);
    for(int i=0; i<n-1; i++){
        string line;
        getline(cin, line);
        stringstream ss(line);
        int u, v, w;       
        ss >> u;
        while(ss >> v && v != -1){
            ss>>w;
            tree[u-1].push_back({v-1, w});
            tree[v-1].push_back({u-1, w});
        }
    }
    
    vector<bool> visited(n);

    stack<pair<int, int>> st;
    visited[0] = true;
    st.push({0, 0});
    int maxR = 0;
    int chNode = 0;
    
    while(!st.empty()){
        auto [curr, R] = st.top();
        if(R>maxR){
            maxR = R;
            chNode = curr;
        }
        st.pop();
        for(auto [next, weight]: tree[curr]){
            if(!visited[next]){
                visited[next] = true;
                st.push({next, weight+R});
            }
        }
    }
    
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    visited[chNode] = true;
    maxR = 0;
    st.push({chNode, 0});
    
    while(!st.empty()){
        auto [curr, R] = st.top();
        if(R>maxR){
            maxR = R;
            chNode = curr;
        }
        st.pop();
        for(auto [next, weight]: tree[curr]){
            if(!visited[next]){
                visited[next] = true;
                st.push({next, weight+R});
            }
        }
    }
    
    cout<<maxR;
    
    return 0;
}