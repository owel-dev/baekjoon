#include <iostream>

using namespace std;

int N;

int grid[65][65];

void recv(int y, int x, int size) {
    int target = grid[y][x];

    if (size == 1) {
        cout << target;
        return;
    }

    bool all = true;

    int end_y = y + size;
    int end_x = x + size;

    for (int i = y; i < end_y; ++i) {
        for (int j = x; j < end_x; ++j) {
            if (grid[i][j] != target) {
                all = false;
            }
        }
    }

    if (all) {
        cout << target;
        return;
    }

    cout << '(';
    size /= 2;
    for (int i = y; i < end_y; i += size) {
        for (int j = x; j < end_x; j += size) {
            recv(i, j, size);
        }
    }
    cout << ')';
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            grid[i][j] = s[j] & 15;
        }
    }

    recv(0, 0, N);
}