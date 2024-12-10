#include <iostream>
#include <vector>

using namespace std;

int white_count = 0; // 하얀색 색종이 개수
int blue_count = 0;  // 파란색 색종이 개수

// 특정 영역이 모두 같은 색인지 확인
bool is_uniform_color(const vector<vector<int>>& paper, int x, int y, int size) {
    int color = paper[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != color) {
                return false;
            }
        }
    }
    return true;
}

// 분할 정복 함수
void divide_and_conquer(const vector<vector<int>>& paper, int x, int y, int size) {
    if (is_uniform_color(paper, x, y, size)) {
        // 영역이 모두 같은 색이면 색종이 개수 증가
        if (paper[x][y] == 0) {
            ++white_count;
        } else {
            ++blue_count;
        }
        return;
    }

    // 4개의 영역으로 분할
    int half = size / 2;
    divide_and_conquer(paper, x, y, half);                 // 왼쪽 위
    divide_and_conquer(paper, x, y + half, half);          // 오른쪽 위
    divide_and_conquer(paper, x + half, y, half);          // 왼쪽 아래
    divide_and_conquer(paper, x + half, y + half, half);   // 오른쪽 아래
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> paper(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> paper[i][j];
        }
    }

    // 분할 정복 시작
    divide_and_conquer(paper, 0, 0, N);

    // 결과 출력
    cout << white_count << "\n" << blue_count << "\n";

    return 0;
}
