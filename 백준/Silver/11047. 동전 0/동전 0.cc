#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin>>N>>K;
    vector<int> coin(N);
    for(int i=0; i<N; i++){
        cin>>coin[N - 1 - i];
    }
    
    int idx = 0;
    int ans = 0;
    while(K != 0 && idx < N){
        ans += (K / coin[idx]);
        K%=coin[idx];
        idx++;
    }
    cout<<ans;
}
