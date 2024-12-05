#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin>>N>>M;
    
    vector<string> nh;
    vector<string> ns;
    
    //hear
    for(int i=0; i<N; i++){
        string name;
        cin>>name;
        nh.push_back(name);
    }
    
    //see
    for(int i=0; i<M; i++){
        string name;
        cin>>name;
        ns.push_back(name);
    }
    
    sort(nh.begin(), nh.end());
    sort(ns.begin(), ns.end());
    
    vector<string> ans;
    int i=0, j=0;
    while(i<nh.size() && j<ns.size()){        
        if(nh[i] == ns[j]){
            ans.push_back(nh[i]);
            i++;
            j++;
        }
        else{
            if(nh[i]<ns[j]) i++;
            else j++;
        }
    }
    
    cout<<ans.size()<<"\n";
    for(auto name: ans){
        cout<<name<<"\n";
    }
    
}