#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> sequence;

void backtrack(int start) {
    if (sequence.size() == M) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < N; i++) {
        sequence.push_back(numbers[i]);
        backtrack(i);
        sequence.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }


    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    N = numbers.size();

    backtrack(0);

    return 0;
}
