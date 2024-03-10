#include <iostream>

using namespace std;

int grid[2188][2188];
int N;
int cnt[3];

void recv(int y, int x, int size) {
//    cout << y << " " << x << " " << size << endl;
    int target = grid[y][x];
    bool all = true;

    int end_y = y + size;
    int end_x = x + size;

    for (int i = y; i < end_y; ++i) {
        for (int j = x; j < end_x; ++j) {
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

    size /= 3;

    for (int i = y; i < end_y; i += size) {
        for (int j = x; j < end_x; j += size) {
            recv(i, j, size);
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

    recv(0, 0, N);

    for (int i: cnt) {
        cout << i << endl;
    }
}