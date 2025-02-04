#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int row = min(x, w-x);
    int col = min(y, h-y);
    cout<<min(row, col);
    
    return 0;
}
