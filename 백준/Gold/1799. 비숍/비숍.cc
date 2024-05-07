#include <iostream>

using namespace std;

int N;
int grid[11][11];
bool visited1[21];
bool visited2[21];
int ans, temp;

const bool BLACK = true;
const bool WHITE = false;

void bt(int num, int count, bool color) {
    if (num >= N * N) {
        return;
    }

    for (int i = num; i < N * N; ++i) {
        int y = i / N;
        int x = i % N;

        if (color == BLACK && (y + x) % 2 == 0) continue;
        if (color == WHITE && (y + x) % 2 != 0) continue;

        if (grid[y][x] == 0) continue;
        if (visited1[y + x] || visited2[y - x + N]) continue;

        visited1[y + x] = true;
        visited2[y - x + N] = true;
        ans = max(ans, count + 1);
        bt(i + 1, count + 1, color);
        visited1[y + x] = false;
        visited2[y - x + N] = false;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    bt(0, 0, WHITE);
    temp = ans;
    ans = 0;

    bt(1, 0, BLACK);
    temp += ans;

    cout << temp;
}
