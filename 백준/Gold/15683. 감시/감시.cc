#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N, M;

int grid[9][9];

vector<pair<int, int> > v;

const int BLANK = 0;
const int WALL = 6;
const int TAKE = 7;

int ans = 999999;

int my[4] = {-1, 0, 1, 0};
int mx[4] = {0, 1, 0, -1};

void take(int y, int x, int toward) {
    toward %= 4;

    while (true) {
        int ny = y + my[toward];
        int nx = x + mx[toward];
        
        y = ny;
        x = nx;

        if (ny < 0 || N <= ny || nx < 0 || M <= nx) break;
        if (grid[ny][nx] == WALL) break;
        if (grid[ny][nx] != BLANK && grid[ny][nx] != TAKE) continue;

        grid[ny][nx] = TAKE;
    }
}

void bt(int count) {
    if (count == v.size()) {
        int blank_count = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == BLANK) blank_count++;
            }
        }

        ans = min(ans, blank_count);
        
        return;
    }

    pair<int, int> p = v[count];

    int y = p.first;
    int x = p.second;
    for (int j = 0; j < 4; ++j) {
        int temp[9][9];
        memcpy(temp, grid, sizeof(int) * 9 * 9);

        if (grid[y][x] == 1) {
            take(y, x, j);
        } else if (grid[y][x] == 2) {
            take(y, x, j);
            take(y, x, j + 2);
        } else if (grid[y][x] == 3) {
            take(y, x, j);
            take(y, x, j + 1);
        } else if (grid[y][x] == 4) {
            take(y, x, j);
            take(y, x, j + 1);
            take(y, x, j + 3);
        } else if (grid[y][x] == 5) {
            take(y, x, j);
            take(y, x, j + 1);
            take(y, x, j + 2);
            take(y, x, j + 3);
        }

        bt(count + 1);
        memcpy(grid, temp, sizeof(int) * 9 * 9);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int num;
            cin >> num;

            if (num != 0 && num != 6) {
                v.push_back({i, j});
            }

            grid[i][j] = num;
        }
    }

    bt(0);

    cout << ans;
}
