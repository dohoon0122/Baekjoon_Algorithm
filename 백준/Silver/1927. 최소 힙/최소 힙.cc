#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
    int N;
    cin>>N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<N; i++){
        int x;
        cin>>x;
        if(x){
            pq.push(x);
        }
        else{
            if(!pq.empty()){
                int ans = pq.top();
                pq.pop();
                cout<<ans<<"\n";
            }
            else{
                cout<<"0"<<"\n";
            }
        }
    }
}