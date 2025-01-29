#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000;
using Matrix = vector<vector<int>>;

Matrix multiply(const Matrix &A, const Matrix &B, int N) {
    Matrix C(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, long long B, int N) {
    Matrix result(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        result[i][i] = 1;

    while (B > 0) {
        if (B % 2 == 1) result = multiply(result, A, N);
        A = multiply(A, A, N);
        B /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    long long B;
    cin>>N>>B;
    
    Matrix A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    
    Matrix ans = power(A, B, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    
    
    return 0;
}
