#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    vector<int> ans;
    set<int> numbers;
    for(int i=0; i<N; i++){
        int temp;
        cin>>temp;
        numbers.insert(temp);
        ans.push_back(temp);
    }
    
    unordered_map<int, int> num_order;
    int order = 0;
    for(auto iter=numbers.begin(); iter!=numbers.end(); iter++){
        num_order[*iter] = order;
        order++;
    }
    
    for(int n: ans){
        cout<<num_order[n]<<" ";
    }
}