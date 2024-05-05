#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int WATER = 0;
const int NO_GROUND = 1;
const int YES_GROUND = 2;
const int GREEN = 3;
const int RED = 4;
const int FLOWER = 5;

int N, M, G, R;
int copy_G, copy_R;
int ans;

int grid[51][51];
pair<int, int> bfs_grid[51][51];

vector<pair<int, int> > grounds;
int ground_size;
int check_ground[11];


int my[4] = {1, -1, 0, 0};
int mx[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void bfs() {
    int flower_count = 0;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;
        int CURR_STATUS = bfs_grid[y][x].first;
        int CURR_COUNT = bfs_grid[y][x].second;

        if (CURR_STATUS == FLOWER) continue;

        for (int i = 0; i < 4; ++i) {
            int ny = y + my[i];
            int nx = x + mx[i];
            int NEXT_STATUS = bfs_grid[ny][nx].first;
            int NEXT_COUNT = bfs_grid[ny][nx].second;

            if (ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
            if (NEXT_STATUS == NO_GROUND || NEXT_STATUS == YES_GROUND) {
                bfs_grid[ny][nx].first = CURR_STATUS;
                bfs_grid[ny][nx].second = CURR_COUNT + 1;
                q.push({ny, nx});
            } else if (CURR_STATUS == GREEN && NEXT_STATUS == RED && CURR_COUNT + 1 == NEXT_COUNT) {
                bfs_grid[ny][nx].first = FLOWER;
                flower_count++;
            } else if (CURR_STATUS == RED && NEXT_STATUS == GREEN && CURR_COUNT + 1 == NEXT_COUNT) {
                bfs_grid[ny][nx].first = FLOWER;
                flower_count++;
            }
        }
    }

    ans = max(ans, flower_count);
}

void set_water(int idx, int count) {
    if (count >= ground_size) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                bfs_grid[i][j] = {grid[i][j], 0};
            }
        }

        for (int i = 0; i < ground_size; ++i) {
            // cout << check_ground[i] << ' '; //

            if (check_ground[i] == GREEN) {
                pair<int, int> p = grounds[i];
                bfs_grid[p.first][p.second] = {GREEN, 0};
                q.push({p.first, p.second});
            } else if (check_ground[i] == RED) {
                pair<int, int> p = grounds[i];
                bfs_grid[p.first][p.second] = {RED, 0};
                q.push({p.first, p.second});
            }
        }
        // cout << endl; //

        bfs();

        return;
    }
    if (copy_G > 0) {
        copy_G--;
        check_ground[idx] = GREEN;
        set_water(idx + 1, count + 1);
        check_ground[idx] = 0;
        copy_G++;
    }
    if (copy_R > 0) {
        copy_R--;
        check_ground[idx] = RED;
        set_water(idx + 1, count + 1);
        check_ground[idx] = 0;
        copy_R++;
    }
    if (copy_G + copy_R < grounds.size() - count) {
        set_water(idx + 1, count + 1);
    }
}

int main() {
    cin >> N >> M >> G >> R;

    copy_G = G;
    copy_R = R;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int num;
            cin >> num;
            grid[i][j] = num;

            if (num == YES_GROUND) {
                grounds.push_back({i, j});
            }
        }
    }
    ground_size = grounds.size();

    set_water(0, 0);

    cout << ans;
}
