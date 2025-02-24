#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, F;
    cin>>N>>F;
    int ans = (N/100)*100;
    int left = ans%F;
    
    cout.width(2);
    cout.fill('0');
    cout<<(F-left)%F;
}
