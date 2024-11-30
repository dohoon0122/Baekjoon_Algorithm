#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N;
    cin>>N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        pq.push({y, x});
    }
    
    while(!pq.empty()){
        auto [y, x] = pq.top();
        pq.pop();
        cout<<x<<" "<<y<<"\n";
    }
}