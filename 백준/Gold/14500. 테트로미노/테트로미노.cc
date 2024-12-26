#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> tetromino = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, // I 모양
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, // ㅁ 모양
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}}, // L 모양
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},  // Z 모양
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {1, -1}, {2, -1}},
    {{0, 0}, {0, 1}, {1, 0}, {1, -1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},  // T 모양
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, -1}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},  // 대칭된 모양
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {1, 0}, {1, -1}, {1, -2}},
    {{0, 0}, {0, 1}, {-1, 1}, {-2, 1}}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin>>N>>M;
    vector<vector<int>> board(N, vector<int>(M));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
        }
    }
    
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(auto& t: tetromino){
                int temp = 0;
                bool valid = true;
                for(auto [dr, dc]: t){
                    int nr = i + dr;
                    int nc = j + dc;
                    if(0<=nr && nr<N && 0<=nc && nc<M) temp+=board[nr][nc];
                    else{
                        valid = false;
                        break;
                    }
                }
                if(valid) ans = max(temp, ans);
            }
        }    
    }
    
    cout<<ans;
    


    return 0;
}