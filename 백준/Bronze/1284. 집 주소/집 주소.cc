#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string n;
    while(cin>>n){
        if(n=="0") break;
        int ans = 1;
        for(char c: n){
            if(c=='1') ans+=2;
            else if(c=='0') ans+=4;
            else ans+=3;
            ans+=1;
        }
        cout<<ans<<"\n";
    }
}