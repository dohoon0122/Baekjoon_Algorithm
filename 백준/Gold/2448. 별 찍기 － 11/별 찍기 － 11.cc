#include <iostream>
#include <vector>

using namespace std;

vector<string> triangle = {
    "  *  ",
    " * * ",
    "*****"
};

void generate(int n) {
    if (n == 3) return;

    int h = n / 2;
    generate(h);

    vector<string> newTriangle(n);
    
    for (int i = 0; i < h; i++) {
        newTriangle[i] = string(h, ' ') + triangle[i] + string(h, ' ');
    }

    for (int i = 0; i < h; i++) {
        newTriangle[h + i] = triangle[i] + " " + triangle[i];
    }

    triangle = newTriangle;
}

int main() {
    int N;
    cin >> N;

    generate(N);

    for (const string &row : triangle) {
        cout << row << "\n";
    }

    return 0;
}
