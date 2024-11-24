#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int N;
    cin>>N;
    stack<int> s;
    s.push(0);
    int curr = 1;
    bool verf = true;
    string ans = "";
    for(int i=0; i<N; i++){
        int goal;
        cin>>goal;
        if(goal > s.top()){
            while(curr<=goal){
                s.push(curr);
                curr++;
                ans+="+";
            }
            s.pop();
            ans+="-";
        }
        else{
            if(goal == s.top()){
                ans+="-";
                s.pop();
            }
            else{
                verf = false;
                break;
            }
        }
    }
    if(verf){
        for(char&c: ans){
            cout<<c<<"\n";
        }
    }
    else{
        cout<<"NO";
    }
}