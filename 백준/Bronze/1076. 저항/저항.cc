#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ohm = {
    {"black", 0},
    {"brown", 1},
    {"red", 2},
    {"orange", 3},
    {"yellow", 4},
    {"green",  5},
    {"blue", 6},
    {"violet", 7},
    {"grey", 8},
    {"white", 9}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b, c;
    cin>>a>>b>>c;
    if(a=="black"){
        if(b=="black"){
            cout<<0;
            return 0;
        }
        cout<<ohm[b];
    }
    else{
        cout<<ohm[a]<<ohm[b];
    }
    for(int i=0;i<ohm[c];i++){
        cout<<"0";
    }
}