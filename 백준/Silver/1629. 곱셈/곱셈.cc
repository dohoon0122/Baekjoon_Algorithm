#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cin>>A>>B>>C;
    
    int max_bit = 0;
    long long curr = B;
    while(curr){
        curr/=2;
        max_bit++;
    }

    long long ans = 1;
    curr = A;
    for(int i=0; i<max_bit; i++){
        curr %= C;
        if(1<<i & B){
            ans*=curr;
            ans%=C;
        }
        curr *= curr;
        
    }
    
    cout<<ans;
    return 0;
}