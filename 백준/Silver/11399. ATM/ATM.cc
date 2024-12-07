#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;
    vector<int> line;
    for(int i=0; i<N; i++){
        int x;
        cin>>x;
        line.push_back(x);
    }
    sort(line.begin(), line.end());
    int ans = 0;
    int prefix_sum = 0;
    for(int d: line){
        prefix_sum += d;
        ans+=prefix_sum;
    }
    cout<<ans<<"\n";
}