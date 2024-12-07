#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin>>N>>M;
    vector<int> arr(N+1);
    for(int i=1; i<=N; i++){
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }    
    
    for(int k=0; k<M; k++){
        int i, j;
        cin>>i>>j;
        cout<<arr[j]-arr[i-1]<<"\n";
    }
}
