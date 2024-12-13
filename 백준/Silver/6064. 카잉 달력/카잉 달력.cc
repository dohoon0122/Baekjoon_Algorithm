#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int N, M, x, y;
        cin>>N>>M>>x>>y;
        
        x--; 
        y--;
        bool found = false;
        
        for (int k = x; k < lcm(N, M); k += N) {
            if (k % M == y) {
                cout << k + 1 << "\n"; // 다시 1-based index로 변환
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << "\n";
        }
    }
}