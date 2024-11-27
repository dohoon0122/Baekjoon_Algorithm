#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    
    vector<int> numbers;
    int sum = 0;
    
    for(int i=0; i<N; i++){
        int temp;
        cin>>temp;
        sum+=temp;
        numbers.push_back(temp);
    }
    
    sort(numbers.begin(), numbers.end());
    unordered_map<int, int> num_count;
    for(int i: numbers){
        num_count[i]++;
    }
    
    priority_queue<pair<int, int>> pq;
    for(auto& [num, freq]: num_count){
        pq.push({freq, -num});
    }
    
    int max_freq = pq.top().first;
    int f_min = -pq.top().second;
    pq.pop();
    if(!pq.empty()){
        int freq = pq.top().first;
        if (freq == max_freq) f_min = -pq.top().second;
    }
    
    
    
    
    // 산술평균
    int m = round(sum/(float)N);
    cout<<m<<"\n";
    // 중앙값
    cout<<numbers[N/2]<<"\n";
    // 최빈값
    cout<<f_min<<"\n";
    // 범위
    cout<<numbers[N-1]-numbers[0]<<"\n";
}
