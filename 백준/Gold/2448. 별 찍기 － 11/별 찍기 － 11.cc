#include <iostream>
#include <cstring>

using namespace std;

int N;

char grid[3100][6200];

void star(int y, int x, int size) {
    if (size == 3) {
        grid[y][x + 2] = '*';
        grid[y + 1][x + 1] = '*';
        grid[y + 1][x + 3] = '*';
        for (int i = 0; i < 5; ++i) {
            grid[y + 2][x + i] = '*';
        }

        return;
    }

    star(y, x + size / 2, size / 2);
    star(y + size / 2, x, size / 2);
    star(y + size / 2, x + size, size / 2);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        memset(grid[i], ' ', N * 2);
    }

    star(0, 0, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N * 2; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }

}