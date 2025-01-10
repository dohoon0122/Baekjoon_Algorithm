#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    vector<vector<int>> tri;
    vector<vector<int>> dp;
    for(int i=0; i<N; i++){
        vector<int> temp(i+1);
        vector<int> init(i+1, 0);
        for(int j=0; j<i+1; j++){
            cin>>temp[j];
        }
        tri.push_back(temp);
        dp.push_back(init);
    }
    dp[0][0] = tri[0][0];
    for(int i=0; i<N-1; i++){
        // i번째 dp[i] = {0, 1, 2, ... i}
        for(int j=0; j<i+1; j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+tri[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+tri[i+1][j+1]);
        }
    }
    int ans = 0;
    for(int i=0; i<N; i++){
        ans = max(ans, dp[N-1][i]);
    }
    cout<<ans;
    return 0;
}