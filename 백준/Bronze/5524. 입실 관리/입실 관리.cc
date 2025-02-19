#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        for(char& c: s){
            if('a'<=c && c<='z'){
                cout<<c;
            }
            else{
                cout<<char(c-'A'+'a');
            }
        }
        cout<<"\n";
    }
}
