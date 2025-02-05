#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> num(3);
    int a,b,c;
    cin>>num[0]>>num[1]>>num[2];
    sort(num.begin(), num.end());
    for(auto& i: num){
        cout<<i<<" ";
    }
    return 0;
}
