#include <iostream>

using namespace std;

int N;
int grid[129][129];
int cnt[2];

int recv(int y, int x, int size) {
    int target = grid[y][x];

    if (size == 1) {
        cnt[target]++;
        return target;
    }

    int end_y = y + size;
    int end_x = x + size;
    size /= 2;

    bool all = true;

    for (int i = y; i < end_y; i += size ) {
        for (int j = x; j < end_x; j += size) {
            if (recv(i, j, size) != target) {
                all = false;
            }
        }
    }

    if (all) {
        cnt[target] -= 3;
        return target;
    }

    return -1;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    recv(0, 0, N);

    for (int i : cnt) {
        cout << i << endl;
    }
}