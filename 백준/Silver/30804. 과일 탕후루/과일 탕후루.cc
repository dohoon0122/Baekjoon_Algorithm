#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;
    vector<int> fruits(N);
    for(int i=0; i<N; i++){
        cin>>fruits[i];
    }
    
    vector<int> fruit_count(10, 0);
    int max_length = 0;
    int left = 0, right = 0;
    int unique_fruits = 0;

    while (right < N) {
        if (fruit_count[fruits[right]] == 0) {
            unique_fruits++;
        }
        fruit_count[fruits[right]]++;

        while (unique_fruits > 2) {
            fruit_count[fruits[left]]--;
            if (fruit_count[fruits[left]] == 0) {
                unique_fruits--;
            }
            ++left;
        }

        max_length = max(max_length, right - left + 1);

        ++right;
    }

    cout<<max_length;
}
