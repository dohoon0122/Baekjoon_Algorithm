#include <iostream>
#include <stack>
using namespace std;

int main(){
    int K;
    cin>>K;
    stack<int> book;
    for(int i=0; i<K; i++){
        int j;
        cin>>j;
        if(j!=0) book.push(j);
        else book.pop();
    }
    int ans = 0;
    int n = book.size();
    while(!book.empty()){
        int temp = book.top();
        ans+=temp;
        book.pop();
    }
    cout<<ans;
}