#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(true){
        cin>>n;
        if(n == 0) break;
        cout<<n*(n+1)/2<<"\n";
    }
    
    return 0;
}
