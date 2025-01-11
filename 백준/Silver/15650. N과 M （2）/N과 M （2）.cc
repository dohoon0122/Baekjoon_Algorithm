#include <iostream>
#include <vector>

using namespace std;

void backtrack(int curr, int N, int idx, int M, vector<int>& seq){
    if(idx == M){
        for(auto& i: seq){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    if(curr>N) return;
    
    seq.push_back(curr);
    backtrack(curr+1, N, idx+1, M, seq);
    seq.pop_back();
    backtrack(curr+1, N, idx, M, seq);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin>>N>>M;
    vector<int> temp;
    backtrack(1, N, 0, M, temp);
    
    
    return 0;
}