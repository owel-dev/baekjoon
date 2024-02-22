#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, P;

string grid[1001];

int width[10];

int cnt[10];

bool visited[1001][1001];

queue<pair<int, int> > q[10];

int my[4] = {-1, 1, 0, 0};
int mx[4] = {0, 0, -1, 1};

int main() {
  cin >> N >> M >> P;

  for (int i = 0; i < P; i++) {
    cin >> width[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> grid[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] != '.' && grid[i][j] != '#') {
        int index = grid[i][j] - 49;
        q[index].push(make_pair(i, j));
        cnt[index]++;
      }
    }
  }

  while (true) {
    bool end_check = true;

    for (int i = 0; i < P; i++) {
      for (int k = 0; k < width[i]; k++) {
        queue<pair<int, int> > q2;

        while (!q[i].empty()) {
          pair<int, int> p = q[i].front();
          q[i].pop();

          int y = p.first;
          int x = p.second;

          for (int j = 0; j < 4; j++) {
            int ny = y + my[j];
            int nx = x + mx[j];

            if (ny < 0 || N <= ny || nx < 0 || M <= nx) continue;

            if (grid[ny][nx] == '.') {
              q2.push(make_pair(ny, nx));
              grid[ny][nx] = i + 49;
              cnt[i]++;
              end_check = false;

            }
          }
        }
        if (q2.empty()) break;
        q[i] = q2;
      }
    }

    if (end_check) break;
  }

  for (int i = 0; i < P; i++) {
    cout << cnt[i] << " ";
  }
}
