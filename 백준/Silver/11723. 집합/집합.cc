#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    vector<bool> in_set(20, false);
    
    for(int i=0; i<N; i++){
        string command;
        cin>>command;
        if(command == "all"){
            for(int j=0; j<20; j++){
                in_set[j] = true;
            }
        }
        else if(command == "empty"){
            for(int j=0; j<20; j++){
                in_set[j] = false;
            }
        }
        else{
            int x;
            cin>>x;
            if(command == "add") in_set[x-1] = true;
            else if(command == "check") cout<<(in_set[x-1]?1:0)<<"\n";
            else if(command == "remove") in_set[x-1] = false;
            else if(command == "toggle") in_set[x-1] = !in_set[x-1];
            else cout<<"error"<<"\n";
        }
        
    }
}