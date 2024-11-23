#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<pair<int, int>> wh;
    for(int i=0; i<N; i++){
        int w, h;
        cin>>w>>h;
        wh.push_back(make_pair(w, h));
    }
    
    for(int i=0; i<N; i++){
        int ans = 1;
        for(int j=0; j<N; j++){
            if(wh[i].first < wh[j].first && wh[i].second < wh[j].second) ans++;
        }
        cout<<ans<<" ";
    }
}
