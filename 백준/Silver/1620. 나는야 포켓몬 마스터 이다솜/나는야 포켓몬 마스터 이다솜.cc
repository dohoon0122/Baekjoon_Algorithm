#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin>>N>>M;
    // name to idx
    unordered_map<string, int> ntoi;
    // idx to name
    vector<string> iton;
    
    for(int i=0; i< N; i++){
        string name;
        cin>>name;
        iton.push_back(name);
        ntoi[name] = i+1;
    }
    
    for(int i=0; i<M; i++){
        string p;
        cin>>p;
        if('0'<=p[0] && p[0] <= '9'){
            cout<<iton[stoi(p) - 1]<<"\n";
        }
        else{
            cout<<ntoi[p]<<"\n";
        }
    }
}