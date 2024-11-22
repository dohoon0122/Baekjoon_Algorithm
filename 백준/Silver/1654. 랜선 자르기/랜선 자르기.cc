#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int K, N;
    cin>>K>>N;
    
    vector<int> line;
    long long left = 1;
    int right = 0;
    for(int i=0; i<K; i++){
        int temp;
        cin>>temp;
        right = right>temp?right:temp;
        line.push_back(temp);
    }
    
    int ans = 0;
    while(left <= right){        
        int mid = left + (right - left) / 2;
        long long number = 0;
        for(int l: line){
            number += l/mid;
        }
        
        if(number < N){
            right = mid - 1;
        }
        else{
            ans = mid;
            left = (long long)mid + 1;
        }
    } 
    

    cout<<ans;
}