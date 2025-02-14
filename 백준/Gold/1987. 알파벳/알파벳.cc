#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m, ans;
vector<string> arr;

void backtrack(int row, int col, vector<int>& char_cnt, int cnt){
    ans = ans>cnt?ans:cnt;
    for(auto& [dr, dc]: dir){
        int n_row = row + dr;
        int n_col = col + dc;
        if(0<=n_row && n_row<n && 0<=n_col && n_col < m){
            char c = arr[n_row][n_col];
            if(char_cnt[c-'A'] == 0){
                char_cnt[c-'A']++;
                backtrack(n_row, n_col, char_cnt, cnt+1);
                char_cnt[c-'A']--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    arr.resize(n, "");
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ans = 0;
    vector<int> char_cnt(26, 0);
    char_cnt[arr[0][0]-'A']++;
    backtrack(0, 0, char_cnt, 1);
    cout<<ans;
}
