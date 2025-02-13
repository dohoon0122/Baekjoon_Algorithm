#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ans = 0;
    for(int i=0; i<8; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<8; j++){
            if(temp[j] == 'F' && (i+j)%2==0) ans++;
        }
    }
    cout<<ans;
}
