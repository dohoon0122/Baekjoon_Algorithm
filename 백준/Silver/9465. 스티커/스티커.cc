#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    
    while(T--){
        int N;
        cin>>N;
        vector<vector<int>> stk(N, vector<int>(2));
        for(int i=0; i<2; i++){
            for(int j=0; j<N; j++){
                cin>>stk[j][i];
            }
        }
        vector<vector<int>> dp(N, vector<int>(2));
        dp[0][0] = stk[0][0];
        dp[0][1] = stk[0][1];
        for(int i=1; i<N; i++){
            dp[i][0] = max(dp[i-1][1] + stk[i][0], dp[i-1][0] - stk[i-1][0] + stk[i][0]);
            dp[i][1] = max(dp[i-1][0] + stk[i][1], dp[i-1][1] - stk[i-1][1] + stk[i][1]);
        }
        
        cout<<max(dp[N-1][0], dp[N-1][1])<<"\n";
    }
    return 0;
}