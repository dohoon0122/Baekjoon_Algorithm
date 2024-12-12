#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, B;
    cin>>N>>M>>B;
    vector<vector<int>> ground(N, vector<int>(M, 0));

    int low = 256;
    int high = 0;

    int total = B;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>ground[i][j];
            total += ground[i][j];
            
            low = min(low, ground[i][j]);
            high = max(high, ground[i][j]);
        }
    }
    
    high = min(high, total/(N*M));
    
    int ans = 512 * N * M;
    int ans_h = 0;
    for(int h = high; h>=low; h--){
        int temp = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(ground[i][j]>h){
                    temp += 2*(ground[i][j] - h);
                }
                else{
                    temp += (h-ground[i][j]);
                }
            }
        }
        if(ans>temp){
            ans = temp;
            ans_h = h;
        }
    }
    cout<<ans<<" "<<ans_h;
}
