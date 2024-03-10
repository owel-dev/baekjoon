#include <iostream>

using namespace std;

int grid[2188][2188];
int N;
int cnt[3];

int recv(int y, int x, int size) {
    int target = grid[y][x];

    if (size == 1) {
        cnt[target + 1]++;
        return target;
    }

    int end_y = y + size;
    int end_x = x + size;
    size /= 3;

    bool all = true;

    for (int i = y; i < end_y; i += size) {
        for (int j = x; j < end_x; j += size) {
            if (recv(i, j, size) != target) {
                all = false;
            }
        }
    }

    if (all) {
        cnt[target + 1] -= 8;
        return target;
    }

    return -2;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    recv(0, 0, N);

    for (int i: cnt) {
        cout << i << endl;
    }
}