#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, B;
    cin>>N>>M>>B;

    int low = 256;
    int high = 0;
    int total = B;
    unordered_map<int, int> height;
    
    for(int i=0; i<N * M; i++){
        int h;
        cin>>h;
        height[h]++;
        
        low = min(low, h);
        high = max(high, h);
        total+=h;
    }
    
    high = min(high, total/(N*M));
    
    int ans = 512 * N * M;
    int ans_h = 0;
    
    for(int d = high; d>=low; d--){
        int temp = 0;
        for(auto [h, cnt]: height){
            if(h > d) temp += 2 * (h - d) * cnt;
            else temp += (d - h) * cnt;
        }

        if(ans > temp){
            ans = temp;
            ans_h = d;
        }
    }
    cout<<ans<<" "<<ans_h;
}
