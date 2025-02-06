#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    while(true){
        string s;
        getline(cin, s);
        if(s=="#") break;
        int ans = 0;
        for(const auto& c: s){
            if(c=='a' || c == 'A' || c == 'e' || c == 'E' || c== 'i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U') ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
