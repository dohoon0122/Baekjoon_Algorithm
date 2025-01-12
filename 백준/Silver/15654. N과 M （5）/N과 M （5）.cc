#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(int N, int idx, int M, vector<int>& numbers, vector<int>& seq, vector<bool>& visited){
    if(idx == M){
        for(auto& i: seq){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=0; i<N; i++){
        if(!visited[i]){
            visited[i] = true;
            seq.push_back(numbers[i]);
            backtrack(N, idx+1, M, numbers, seq, visited);
            
            visited[i] = false;
            seq.pop_back();
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin>>N>>M;
    vector<int> numbers(N);
    for(int i=0; i<N; i++){
        cin>>numbers[i];
    }
    
    sort(numbers.begin(), numbers.end());
    
    vector<int> temp;
    vector<bool> visited(N, false);
    backtrack(N, 0, M, numbers, temp, visited);
    
    
    return 0;
}