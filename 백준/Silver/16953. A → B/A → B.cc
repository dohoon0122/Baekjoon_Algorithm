#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin>>A>>B;
    
    queue<pair<int, int>> q;
    q.push({A, 1});
    
    int ans = -1;
    
    while(!q.empty()){
        auto [curr, depth] = q.front();
        q.pop();
        if(curr > B) continue;
        if(curr == B){
            ans = depth;
            break;
        }
        if (curr <= INT_MAX / 2) {
            q.push({curr * 2, depth + 1});
        }
        if (curr <= (INT_MAX - 1) / 10) {
            q.push({curr * 10 + 1, depth + 1});
        }
    }
    
    cout<<ans;
    
    return 0;
}