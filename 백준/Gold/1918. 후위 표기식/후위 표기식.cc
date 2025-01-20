#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int order(char op){
    if(op=='(') return 0;
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input, output;
    stack<char> st;
    
    cin>>input;
    
    for(char ch: input){
        if('A'<=ch && ch<='Z'){
            output += ch;
        }
        else if(ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            while(!st.empty() && st.top() != '('){
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && order(st.top()) >= order(ch)){
                output += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    
    while(!st.empty()){
        output += st.top();
        st.pop();
    }
        
    cout<<output;
    
    return 0;
}