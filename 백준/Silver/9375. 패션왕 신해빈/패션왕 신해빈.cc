#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int N;
        cin>>N;
        unordered_map<string, int> fashion;
        for(int j=0; j<N; j++){
            string c, type;
            cin>>c>>type;
            fashion[type]++;
        }
        
        int ans = 1;
        for(auto [style, cnt]: fashion){
            ans*=(cnt+1);
        }
        cout<<ans - 1<<"\n";
    }
}
