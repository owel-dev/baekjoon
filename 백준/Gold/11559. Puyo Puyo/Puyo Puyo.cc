#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char grid[13][7];
bool visited[13][7];

int my[4] = {-1, 1, 0, 0};
int mx[4] = {0, 0, -1, 1};

queue<pair<int, int> > q;

bool chain_flag;
int chain_cnt;

void bfs(char color) {
    int cnt = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = p.first + my[i];
            int nx = p.second + mx[i];

            if (visited[ny][nx]) continue;
            if (ny < 0 || 12 <= ny || nx < 0 || 6 <= nx) continue;

            if (grid[ny][nx] == color) {
                q.push({ny, nx});
                visited[ny][nx] = true;
                cnt++;
            }
        }
    }

    if (cnt >= 4) {
        chain_flag = true;

        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (!visited[i][j]) continue;
                grid[i][j] = '.';
            }
        }
    }
}

void pull_grid() {
    for (int i = 0; i < 6; ++i) {
        bool dot_flag = false;
        int dot_potistion;

        for (int j = 12 - 1; j >= 0; --j) {
            if (!dot_flag && grid[j][i] == '.') {
                dot_flag = true;
                dot_potistion = j;
            } else if (dot_flag && grid[j][i] != '.') {
                grid[dot_potistion][i] = grid[j][i];
                grid[j][i] = '.';
                j = dot_potistion;
                dot_flag = false;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> grid[i][j];
        }
    }

    while (true) {
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (grid[i][j] == '.' || visited[i][j]) continue;

                q.push({i, j});
                visited[i][j] = true;

                bfs(grid[i][j]);

                memset(visited, false, sizeof(char) * 13 * 7);
            }
        }

        if (!chain_flag) break;
        chain_flag = false;
        chain_cnt++;

        pull_grid();
    }

    cout << chain_cnt;
}
