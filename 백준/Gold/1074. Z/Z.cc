#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, r, c;
    cin>>N>>r>>c;
    
    int ans = 0;
    int d = 1<<N;
    while(r || c){
        int box = (d/2)*(d/2);
        if(r<d/2){
            // 0
            if(c<d/2){
                // do nothing
            }
            // 1
            else{
                c -= (d/2);
                ans += box;
            }
        }
        else{
            // 2
            if(c<d/2){
                r -= (d/2);
                ans += (box * 2);
            }
            // 3
            else{
                r -= (d/2);
                c -= (d/2);
                ans += (box * 3);
            }
        }
        d/=2;
    }
    cout<<ans;
}