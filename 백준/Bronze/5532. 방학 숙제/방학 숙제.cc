#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L, A, B, C, D;
    cin>>L>>A>>B>>C>>D;
    int a = A/C + (A%C?1:0);
    int b = B/D + (B%D?1:0);
    int c = a>b?a:b;
    cout<<L-c;
}
