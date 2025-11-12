#include <iostream>
#include <queue>

using namespace std;

int N, K, L;

int map[101][101];
const int EMPTY = 0;
const int APPLE = 1;
const int SNAKE = 2;

char rotation[10001];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

int y = 0; int x = 0;
queue<pair<int, int>> snake;

int main() {
  cin >> N >> K;
  while (K--) {
    int y, x;
    cin >> y >> x;
    map[y - 1][x - 1] = APPLE;
  }

  cin >> L;
  while (L--) {
    int time;
    char dir;
    cin >> time >> dir;
    rotation[time] = dir;
  }

  int time = 0;
  snake.push({0, 0});
  map[0][0] = SNAKE;
  int dir = EAST;
  y = 0; x = 0;
  while (true) {
    time++;

    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (ny < 0 || N <= ny || nx < 0 || N <= nx) break;
    if (map[ny][nx] == SNAKE) break;

    if (map[ny][nx] == EMPTY) {
      pair<int, int> tail = snake.front(); snake.pop();
      map[tail.first][tail.second] = EMPTY;
    }

    y = ny;
    x = nx;
    map[y][x] = SNAKE;
    snake.push({y, x});

    if (rotation[time] == 'L') {
      dir = (dir + 3) % 4;
    } else if (rotation[time] == 'D') {
      dir = (dir + 1) % 4;
    }
  }
  
  cout << time << endl;
}