#include <iostream>
#include <queue>
using namespace std;
char grid[6][6];
bool visited[26];
int sequence[8];
int my[4] = {1, -1, 0, 0};
int mx[4] = {0 ,0, 1, -1};
int ans;

bool bfs() {
    int count = 0;
    bool s_grid[6][6] = {false};
    bool b_visited[6][6] = {false};

    for (int i = 0; i < 7; ++i) {
        int num = sequence[i];
        s_grid[num / 5][num % 5] = true;
    }

    queue<pair<int, int> > q;
    int first_y = sequence[0] / 5;
    int first_x = sequence[0] % 5;
    q.push({first_y, first_x});
    b_visited[first_y][first_x] = true;
    count++;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = p.first + my[i];
            int nx = p.second + mx[i];

            if (ny < 0 || 5 <= ny || nx < 0 || 5 <= nx) continue;
            if (b_visited[ny][nx] || !s_grid[ny][nx]) continue;
            q.push({ny, nx});
            b_visited[ny][nx] = true;
            count++;
        }
    }
    if (count == 7) return true;
    return false;
}

void bt(int min, int size, int s_count) {
    if (4 <= size - s_count) {
        return;
    }

    if (size == 7 && 4 <= s_count) {
        if (bfs()) {
            ans++;
        }
        return;
    }

    for (int i = min; i < 25; ++i) {
        if (visited[i]) continue;
        visited[i] = true;

        sequence[size] = i;

        int is_s = grid[i / 5][i % 5] == 'S' ? 1 : 0;

        bt(i + 1, size + 1, s_count + is_s);

        visited[i] = false;
    }
}

int main() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> grid[i][j];
        }
    }

    bt(0, 0, 0);
    cout << ans;
}
