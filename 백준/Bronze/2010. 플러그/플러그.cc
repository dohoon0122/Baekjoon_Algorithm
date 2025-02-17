#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    int ans = 1;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        ans += temp-1;
    }
    cout<<ans;
}