#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int MAXNUM = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    for(int i=0; i<T; i++){
        int start, target;
        cin>>start>>target;
        
        vector<string> cal(MAXNUM);
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            string order = cal[curr];
            if(curr == target){
                cout<<order<<"\n";
                break;
            }
            
            vector<int> next(4);
            int D = (curr * 2) % MAXNUM;
            int S = (curr + 9999) % MAXNUM;
            int L = (curr%1000)*10 + (curr/1000);
            int R = (curr/10) + (curr%10)*1000;
            
            if(cal[D].empty()){
                q.push(D);
                cal[D] = order+"D";
            }
            if(cal[S].empty()){
                q.push(S);
                cal[S] = order+"S";
            }
            if(cal[L].empty()){
                q.push(L);
                cal[L] = order+"L";
            }
            if(cal[R].empty()){
                q.push(R);
                cal[R] = order+"R";
            }
                       
        }
        
    }

    return 0;
}