#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin>>N>>M;
    
    vector<vector<int>> array(N+1, vector<int>(N+1, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>array[i+1][j+1];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            array[i][j] += array[i-1][j] + array[i][j-1] - array[i-1][j-1];
        }
    }
    
    
    for(int i=0; i<M; i++){
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<array[x2][y2] - array[x2][y1-1] - array[x1-1][y2] + array[x1-1][y1-1]<<"\n";
    }
    
    
    return 0;
}