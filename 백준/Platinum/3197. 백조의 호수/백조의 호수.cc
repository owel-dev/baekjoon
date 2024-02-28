#include <unistd.h>

#include <iostream>
#include <queue>

using namespace std;

int R, C;
char MAP[1501][1501];
pair<int, int> swan_pos;

queue<pair<int, int> > water_Q;
queue<pair<int, int> > water_NQ;
queue<pair<int, int> > swan_Q;
queue<pair<int, int> > swan_NQ;

bool visited[1501][1501];

int my[4] = {-1, 1, 0, 0};
int mx[4] = {0, 0, -1, 1};

int day;

bool is_meet;

void swan_bfs() {
  while (!swan_Q.empty() && !is_meet) {
    pair<int, int> p = swan_Q.front();
    swan_Q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = p.first + my[i];
      int nx = p.second + mx[i];

      if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;
      if (visited[ny][nx]) continue;

      visited[ny][nx] = true;

      if (MAP[ny][nx] == '.') {
        swan_Q.push({ny, nx});
      } else if (MAP[ny][nx] == 'X') {
        swan_NQ.push({ny, nx});
      } else if (MAP[ny][nx] == 'L') {
        is_meet = true;
        return;
      }
    }
  }
}

void water_bfs() {
  while (!water_Q.empty()) {
    pair<int, int> p = water_Q.front();
    water_Q.pop();

    for (int k = 0; k < 4; k++) {
      int ny = p.first + my[k];
      int nx = p.second + mx[k];

      if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;

      if (MAP[ny][nx] == 'X') {
        water_NQ.push({ny, nx});
        MAP[ny][nx] = '.';
      }
    }
  }
}

int main() {
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> MAP[i][j];

      if (MAP[i][j] == '.') water_Q.push({i, j});
      if (MAP[i][j] == 'L') {
        water_Q.push({i, j});
        swan_pos = {i, j};
      }
    }
  }
  swan_Q.push({swan_pos.first, swan_pos.second});
  visited[swan_pos.first][swan_pos.second] = true;

  while (true) {
    swan_bfs();
    if (is_meet) {
      cout << day << endl;
      return 0;
    }
    swan_Q = swan_NQ;
    while (!swan_NQ.empty()) swan_NQ.pop();

    water_bfs();
    water_Q = water_NQ;
    while (!water_NQ.empty()) water_NQ.pop();

    day++;
  }
}
