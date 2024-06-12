#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

const int NOVISITED = -1;

bool qube[5][5][5];
bool case_cube[4][5][5][5];
bool reloc_cube[5][5][5];

int rotate_combi[5];
int stack_combi[5];
bool stack_combi_check[5];

int mz[6] = {-1, 1, 0, 0, 0, 0};
int my[6] = {0, 0, -1, 1, 0, 0};
int mx[6] = {0, 0, 0, 0, -1, 1};

queue<tuple<int, int, int> > q;
int visited[5][5][5];

int ans = -1;

void input() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                int num;
                cin >> num;
                qube[i][j][k] = num;
            }
        }
    }
}

void set_rotate_case() {
    for (int i = 0; i < 5; ++i) {
        for (int dir = UP; dir <= LEFT; ++dir) {
            switch (dir) {
                case UP:
                    for (int j = 0; j < 5; ++j) {
                        for (int l = 0; l < 5; ++l) {
                            case_cube[dir][i][j][l] = qube[i][j][l];
                        }
                    }
                    break;
                case RIGHT:
                    for (int j = 0; j < 5; ++j) {
                        for (int l = 0; l < 5; ++l) {
                            case_cube[dir][i][j][l] = qube[i][4 - l][j];
                        }
                    }
                    break;
                case DOWN:
                    for (int j = 0; j < 5; ++j) {
                        for (int l = 0; l < 5; ++l) {
                            case_cube[dir][i][j][l] = qube[i][4 - j][4 - l];
                        }
                    }
                    break;
                case LEFT:
                    for (int j = 0; j < 5; ++j) {
                        for (int l = 0; l < 5; ++l) {
                            case_cube[dir][i][j][l] = qube[i][l][4 - j];
                        }
                    }
                    break;
            }
        }
    }
}

void relocation() {
    memset(reloc_cube, 0, sizeof(bool) * 5 * 5 * 5);

    for (int i = 0; i < 5; ++i) {
        int order = stack_combi[i];
        int dir = rotate_combi[i];

        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                reloc_cube[order][j][k] = case_cube[dir][i][j][k];
            }
        }
    }
}

int bfs() {
    if (!reloc_cube[0][0][0] || !reloc_cube[4][4][4]) return -1;

    while (!q.empty()) {
        q.pop();
    }

    memset(visited, NOVISITED, sizeof(int) * 5 * 5 * 5);

    q.push({0, 0, 0});
    visited[0][0][0] = 0;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int curr_z = get<0>(curr);
        int curr_y = get<1>(curr);
        int curr_x = get<2>(curr);
        int curr_count = visited[curr_z][curr_y][curr_x];

        for (int i = 0; i < 6; ++i) {
            int nz = curr_z + mz[i];
            int ny = curr_y + my[i];
            int nx = curr_x + mx[i];

            if (nz < 0 || ny < 0 || nx < 0) continue;
            if (5 <= nz || 5 <= ny || 5 <= nx) continue;
            if (visited[nz][ny][nx] != NOVISITED || !reloc_cube[nz][ny][nx]) continue;

            q.push({nz, ny, nx});
            visited[nz][ny][nx] = curr_count + 1;

            if (nz == 4 && ny == 4 && nx == 4) {
                return visited[nz][ny][nx];
            }
        }
    }

    return -1;
}


void stack_combination(int index) {
    if (index == 5) {
        relocation();

        int count = bfs();

        if (count == -1) {
            return;
        }

        if (ans == -1) {
            ans = count;
            return ;
        }

        ans = min(ans, count);
        return;
    }

    for (int i = 0; i < 5; ++i) {
        if (!stack_combi_check[i]) {
            stack_combi_check[i] = true;
            stack_combi[index] = i;
            stack_combination(index + 1);
            stack_combi_check[i] = false;
        }
    }
}

void rotate_combination(int index) {
    if (index == 5) {
        stack_combination(0);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        rotate_combi[index] = i;
        rotate_combination(index + 1);
    }
}

int main() {
    input();
    set_rotate_case();
    rotate_combination(0);

    cout << ans;
}
