#include <iostream>

using namespace std;

int N, M, K;
int y, x;

int grid[20][20];

const int EAST = 1;
const int WEST = 2;
const int NORTH = 3;
const int SOUTH = 4;

int dice[6];

const int UP = 0;
const int FRONT = 1;
const int RIGHT = 2;
const int LEFT = 3;
const int BACK = 4;
const int DOWN = 5;

bool is_valid_roll(int dir) {
    switch (dir) {
        case EAST:
            if (M <= x + 1) return false;
            x++;
            break;
        case WEST:
            if (x - 1 < 0) return false;
            x--;
            break;
        case NORTH:
            if (y - 1 < 0) return false;
            y--;
            break;
        case SOUTH:
            if (N <= y + 1) return false;
            y++;
            break;
    }

    return true;
}

void roll(int dir) {
    int temp = dice[UP];
    switch (dir) {
        case EAST:
            dice[UP] = dice[LEFT];
            dice[LEFT] = dice[DOWN];
            dice[DOWN] = dice[RIGHT];
            dice[RIGHT] = temp;
            break;
        case WEST:
            dice[UP] = dice[RIGHT];
            dice[RIGHT] = dice[DOWN];
            dice[DOWN] = dice[LEFT];
            dice[LEFT] = temp;
            break;
        case NORTH:
            dice[UP] = dice[BACK];
            dice[BACK] = dice[DOWN];
            dice[DOWN] = dice[FRONT];
            dice[FRONT] = temp;
            break;
        case SOUTH:
            dice[UP] = dice[FRONT];
            dice[FRONT] = dice[DOWN];
            dice[DOWN] = dice[BACK];
            dice[BACK] = temp;
            break;
    }
}

int main() {
    cin >> N >> M >> y >> x >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < K; ++i) {
        int dir;
        cin >> dir;

        if (!is_valid_roll(dir)) continue;

        roll(dir);

        if (grid[y][x] == 0) {
            grid[y][x] = dice[DOWN];
        } else {
            dice[DOWN] = grid[y][x];
            grid[y][x] = 0;
        }

        cout << dice[UP] << endl;
    }
}
