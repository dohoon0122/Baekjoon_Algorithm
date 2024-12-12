#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(int i=0; i<N; i++){
        int temp;
        cin>>temp;
        if(temp!=0){
            if(temp>0){
                pq.push({temp, 1});
            }
            else{
                pq.push({-temp, -1});
            }
        }
        else{
            if(pq.empty()) cout<<"0"<<"\n";
            else{
                auto [curr, sign] = pq.top();
                pq.pop();
                cout<<curr*sign<<"\n";
            }
        }
    }
}
