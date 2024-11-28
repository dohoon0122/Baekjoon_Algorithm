#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        stack<char> verf;
        for(char c: str){
            if(c=='('||c==')'||c=='['||c==']'){
                if(verf.size()!=0 && verf.top()=='(' && c == ')') verf.pop();
                else if(verf.size()!=0 && verf.top()=='[' && c==']') verf.pop();
                else verf.push(c);
            }
        }
        if(str!="."){
            if(verf.size()==0) cout<<"yes"<<"\n";
            else cout<<"no"<<"\n";
        } 
    }
}
