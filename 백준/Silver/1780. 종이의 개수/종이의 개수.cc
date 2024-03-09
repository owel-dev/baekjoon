#include <iostream>
#include <cmath>

using namespace std;

int grid[2188][2188];

int N;

int cnt[3];

int c;
void recv(int y1, int x1, int y2, int x2) {
    c++;
    int target = grid[y1][x1];
    bool all = true;

    for (int i = y1; i <= y2; ++i) {
        for (int j = x1; j <= x2; ++j) {
            if (grid[i][j] != target) {
                all = false;
                break;
            }

        }
    }

    if (all) {
        cnt[target + 1] += 1;
        return;
    }

    int gap = (y2 - y1) / 3;

    for (int i = y1; i <= y2; i += gap + 1) {
        for (int j = x1; j <= x2; j += gap + 1) {
            recv(i, j, i + gap, j + gap);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    recv(0, 0, N - 1, N - 1);

    for (int i : cnt) {
        cout << i << endl;
    }
}