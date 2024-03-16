#include <iostream>
#include <cstring>

using namespace std;

int N;
char grid[2200][2200];

void star(int size) {
    if (size == 3) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == 1 && j == 1) continue;
                else grid[i][j] = '*';
            }
        }
        return;
    }

    star(size / 3);

    int gap = size / 3;
    for (int i = 0; i < size; i += gap) {
        for (int j = 0; j < size; j += gap) {
            if (i == gap && j == gap) continue;
            for (int k = 0; k < gap; ++k) {
                for (int l = 0; l < gap; ++l) {
                    grid[i + k][j + l] = grid[k][l];
                }
            }
        }
    }
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        memset(grid[i], ' ', N);
    }

    star(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}