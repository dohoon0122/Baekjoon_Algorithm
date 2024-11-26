#include <iostream>
#include <queue>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int N, M;
        cin>>N>>M;
        priority_queue<int> pq;
        queue<pair<int, int>> q; // idx, priority
        int cnt = 0;
        
        for(int j=0; j<N; j++){
            int p;
            cin>>p;
            pq.push(p);
            q.push({j, p});
        }
        while(!q.empty()){
            auto [idx, priority] = q.front();
            q.pop();
            if(priority != pq.top()){
                q.push({idx, priority});
            }
            else{
                pq.pop();
                cnt++;
                if(idx == M){
                    cout<<cnt<<"\n";
                }
            }
        }
    }
}