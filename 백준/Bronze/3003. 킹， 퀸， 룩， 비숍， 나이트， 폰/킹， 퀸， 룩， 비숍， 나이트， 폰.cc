#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> ans = {1, 1, 2, 2, 2, 8};
    vector<int> chess(6, 0);
    for(int i=0; i<6; i++){
        cin>>chess[i];
        cout<<(ans[i] - chess[i])<<" ";
    }
}
