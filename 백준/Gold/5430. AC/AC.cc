#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        string order, array;
        int N;
        cin>>order;
        cin>>N;
        cin>>array;
        
        vector<int> arr;
        string temp = "";
        if(N>0){
            for(int j=1; j<array.size(); j++){
                if(array[j] == ',' || array[j] == ']'){
                    if(!temp.empty()){
                        arr.push_back(stoi(temp));
                        temp = "";
                    }     
                }
                else{
                    temp+=array[j];
                }
            }
        }
        
        
        bool reverse = false;
        int del_cnt = 0;
        int left = 0;
        int right = N-1;
        bool valid = true;
        
        for(char o: order){
            if(o=='R'){
                reverse = !reverse;
            }
            else if(o=='D'){
                del_cnt++;
                if(del_cnt > N){
                    valid = false;
                    break;
                }
                else{
                    if(!reverse){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
            else{
                valid = false;
                break;
            }
        }
        
        if(valid){
            cout << "[";
            string result = "";
            if(del_cnt != N){
                if (!reverse) {
                    for (int j = left; j <= right; j++) {
                        result += to_string(arr[j]) + ",";
                    }
                } 
                else {
                    for (int j = right; j >= left; j--) {
                        result += to_string(arr[j]) + ",";
                    }
                }
                result.pop_back(); 
            }        
            cout << result << "]\n";
        }
        else{
            cout<<"error"<<"\n";
        }
        
    }
    return 0;
}