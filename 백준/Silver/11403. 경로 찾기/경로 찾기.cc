#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    vector<vector<int>> arr(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(arr[i][j]==1) continue;
                else{
                    arr[i][j] = arr[i][k]*arr[k][j];
                }
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

