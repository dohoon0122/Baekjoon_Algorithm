#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    unordered_map<int, int> ladder;
    unordered_map<int, int> snake;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a] = b;
    }
    
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        snake[a] = b;
    }
    
    vector<int> board(101, 100);
    queue<int> q;
    q.push(1);
    board[1] = 0;
    
    while(!q.empty()){
        int curr = q.front();
        int cnt = board[curr];
        q.pop();
        
        if(curr == 100){
            cout<<cnt;
            break;
        }
        
        for(int i=1; i<=6; i++){
            int next = curr + i;
            if(next>100) break;
            
            if(ladder.count(next)) next = ladder[next];
            else if(snake.count(next)) next = snake[next];
            
            if(board[next] > cnt + 1){
                board[next] = cnt + 1;
                q.push(next);
            }   
        }      
    }
    

    return 0;
}