#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int ans = 0;
    for(int i=2023; i<=n; i++){
        string s = to_string(i);
        int c = 0;
        for(char& ch: s){
            if(c == 4) {
                break;
            }
            switch(c){
                case 0:
                    if(ch=='2') c++;
                    break;
                case 1:
                    if(ch=='0') c++;
                    break;
                case 2:
                    if(ch=='2') c++;
                    break;
                case 3:
                    if(ch=='3'){
                        c++;
                        ans++;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    cout<<ans;
}