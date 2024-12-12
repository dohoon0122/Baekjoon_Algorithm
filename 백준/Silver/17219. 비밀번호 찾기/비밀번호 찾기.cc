#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin>>N>>M;
    unordered_map<string, string> spw;
    for(int i=0; i<N; i++){
        string site, pw;
        cin>>site>>pw;
        spw[site] = pw;
    }
    for(int i=0; i<M; i++){
        string site;
        cin>>site;
        cout<<spw[site]<<"\n";
    }
}
