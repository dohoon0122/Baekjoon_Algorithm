#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    string number = "";
    bool m_prev = false;
    int ans = 0;
    
    cin>>s;
    s+="+";
    
    for(const char& c: s){
        if(c == '+' || c == '-'){
            if(m_prev) ans -= stoi(number);
            else ans += stoi(number);
                       
            number  = "";
            
            if(c == '-') m_prev = true;
        }
        else{
            number+=c;
        }
    }
    
    cout<<ans;
}