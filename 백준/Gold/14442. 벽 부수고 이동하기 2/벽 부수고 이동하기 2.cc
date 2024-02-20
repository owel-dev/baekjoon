#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;

string grid[1001];
bool visited[1001][1001][11];
queue<tuple<int, int, int, int> > q;
int my[4] = {-1, 1, 0, 0};
int mx[4] = {0, 0, -1, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K;

  for (int i = 0; i < N; i++) {
    cin >> grid[i];
  }

  q.push(make_tuple(0, 0, 1, 0));
  visited[0][0][0] = true;
  while (!q.empty()) {
    tuple<int, int, int, int> t = q.front();
    q.pop();
    int y = get<0>(t);
    int x = get<1>(t);
    int cnt = get<2>(t);
    int wall = get<3>(t);

    if (y == N - 1 && x == M - 1) {
      cout << cnt << endl;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int ny = y + my[i];
      int nx = x + mx[i];

      if (ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
      if (grid[ny][nx] == '0' && !visited[ny][nx][wall]) {
        q.push(make_tuple(ny, nx, cnt + 1, wall));
        visited[ny][nx][wall] = true;
      } else if (grid[ny][nx] == '1' && !visited[ny][nx][wall + 1] &&
                 wall < K) {
        q.push(make_tuple(ny, nx, cnt + 1, wall + 1));
        visited[ny][nx][wall + 1] = true;
      }
    }
  }
  cout << -1 << endl;
}
