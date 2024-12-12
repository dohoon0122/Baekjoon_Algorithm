#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    vector<int> dp(50001, 4);
    dp[0] = 0;

    for(int i=1; i<224; i++){
        dp[i*i] = 1;
        for(int j = i*i; j<50001; j++){
            dp[j] = min(dp[j], dp[j-i*i] + 1);
        }
    }
    
    cin>>N;
    cout<<dp[N];
    
}
