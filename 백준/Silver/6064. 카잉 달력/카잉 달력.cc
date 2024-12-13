#include <iostream>
#include <vector>
#include <numeric> // for gcd

using namespace std;

// 최대공약수(GCD)를 이용해 모듈러 역원을 계산 (확장된 유클리드 알고리즘)
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        // m은 a % m이 된다
        m = a % m, a = t;
        t = x0;

        // x0는 x1 - q * x0이 된다
        x0 = x1 - q * x0;
        x1 = t;
    }

    // x1이 음수일 경우 양수로 변환
    if (x1 < 0) x1 += m0;

    return x1;
}

// 중국인의 나머지 정리 (CRT) 구현
int crt(int n1, int r1, int n2, int r2) {
    int g = gcd(n1, n2);

    if (g == 1) {
        // n1과 n2가 서로소인 경우 일반 CRT 적용
        int inv_n1 = mod_inverse(n1, n2);
        int x = (r1 + n1 * ((r2 - r1) * inv_n1 % n2)) % (n1 * n2);
        if (x < 0) x += n1 * n2;
        return x;
    } else {
        // n1과 n2가 서로소가 아닌 경우 특별한 계산
        if ((r2 - r1) % g != 0) {
            return -1; // 해가 없는 경우
        }

        // n1과 n2를 g로 나눔
        n1 /= g;
        n2 /= g;
        int new_r1 = r1 % g;
        int new_r2 = r2 % g;

        // 새로운 계수를 계산
        int t = ((r2 - r1) / g) % n2;
        int inv_n1 = mod_inverse(n1, n2);
        t = (t * inv_n1 % n2);
        if (t < 0) t += n2;

        // 최종 결과 계산
        int x = r1 + g * (n1 * t);
        return x % (n1 * g * n2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // 테스트 케이스 수
    cin >> T;

    while (T--) {
        int N, M, x, y;
        cin >> N >> M >> x >> y;

        // 1-based index를 0-based로 변환
        x--; 
        y--;

        // CRT를 적용하여 해를 구함
        int result = crt(N, x, M, y);

        if (result == -1) {
            cout << -1 << "\n";
        } else {
            // 결과를 다시 1-based index로 변환하여 출력
            cout << result + 1 << "\n";
        }
    }

    return 0;
}