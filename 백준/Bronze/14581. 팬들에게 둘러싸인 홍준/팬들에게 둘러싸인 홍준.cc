#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string fan = ":fan:";
    string id;
    cin>>id;
    for(int i=0; i<3; i++){
        cout<<fan;
    }
    cout<<"\n";
    cout<<fan<<":"<<id<<":"<<fan<<"\n";
    for(int i=0; i<3; i++){
        cout<<fan;
    }
    
    return 0;
}
