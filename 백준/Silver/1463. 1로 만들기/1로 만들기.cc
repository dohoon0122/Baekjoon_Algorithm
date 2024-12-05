#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    vector<int> dp(N+1, INT_MAX);
    dp[1] = 0;
    for(int i=1; i<=N; i++){
        int curr = dp[i];
        if(i+1<=N) dp[i+1] = min(dp[i+1], curr+1);
        if(i*2<=N) dp[i*2] = min(dp[i*2], curr+1);
        if(i*3<=N) dp[i*3] = min(dp[i*3], curr+1);
    }
    cout<<dp[N];
}