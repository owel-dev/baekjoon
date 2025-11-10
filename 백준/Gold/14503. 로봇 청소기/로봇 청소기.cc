#include <iostream>
using namespace std;

int N, M;
int r, c, d;
int map[51][51];

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

const int UNCLEAN = 0;
const int WALL = 1;
const int CLEAN = 2;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int cleanCount = 0;

int main() {
  cin >> N >> M;
  cin >> r >> c >> d;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
    }
  }

  int y = r;
  int x = c;
  int dir = d;
  while (true) {
    if (map[y][x] == UNCLEAN) {
      map[y][x] = CLEAN;
      cleanCount++;
    }

    bool isUnclean = false;
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (map[ny][nx] == UNCLEAN) {
        isUnclean = true;
        break;
      }
    }

    if (isUnclean) {
      while (isUnclean) {
        if (dir == NORTH) {
          dir = WEST;
        } else if (dir == EAST) {
          dir = NORTH;
        } else if (dir == SOUTH) {
          dir = EAST;
        } else if (dir == WEST) {
          dir = SOUTH;
        }

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || N <= ny || nx < 0 || M <= nx) continue;

        if (map[ny][nx] == UNCLEAN) {
          y = ny;
          x = nx;
          break;
        }
      }
    } else {
      int backDir;

      if (dir == NORTH) {
        backDir = SOUTH;
      } else if (dir == EAST) {
        backDir = WEST;
      } else if (dir == SOUTH) {
        backDir = NORTH;
      } else if (dir == WEST) {
        backDir = EAST;
      }

      int ny = y + dy[backDir];
      int nx = x + dx[backDir];

      if (ny < 0 || N <= ny || nx < 0 || M <= nx) continue;

      if (map[ny][nx] == WALL) {
        break;
      }

      y = ny;
      x = nx;
    }
  }

  cout << cleanCount << endl;
}