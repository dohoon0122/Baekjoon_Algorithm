#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin>>s;
    for(auto& c: s){
        if('a'<=c && c<='z'){
            c-='a';
            c+='A';
        }
        else{
            c-='A';
            c+='a';
        }
    }
    cout<<s;
}