#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> tree(N);
    int right = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        right = max(right, tree[i]);
    }
    
    int left = 0;
    int ans = 0;
    
    while (left <= right) { 
        int mid = left + (right - left) / 2;
        long long my = 0;
        
        for (auto t : tree) {
            if (t > mid) { 
                my += (t - mid);
            }
        }
        
        if (my < M) { 
            right = mid - 1; 
        } else {
            ans = mid; 
            left = mid + 1; 
        }
    }
    
    cout << ans << "\n"; 
    return 0;
}
