#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int K, W, H;

int grid[201][201];
bool visited[201][201][31];

int my_h[12] = {-2, -1, 1, 2, 2, 1, -1, -2};
int mx_h[12] = {1, 2, 2, 1, -1, -2, -2, -1};

int my[4] = {-1, 1, 0, 0};
int mx[4] = {0, 0, -1, 1};

queue<tuple<int, int, int, int> > q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> K >> W >> H;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      q.push(make_tuple(0, 0, 0, 0));
      visited[0][0][0] = true;

      while (!q.empty()) {
        tuple<int, int, int, int> t = q.front();
        q.pop();

        int t_y = get<0>(t);
        int t_x = get<1>(t);
        int cnt = get<2>(t);
        int ability = get<3>(t);

        if (t_y == H - 1 && t_x == W - 1) {
          cout << cnt;
          return 0;
        }

        if (ability < K) {
          for (int i = 0; i < 8; i++) {
            int y = t_y + my_h[i];
            int x = t_x + mx_h[i];
            if (y < 0 || H <= y || x < 0 || W <= x) continue;
            if (grid[y][x] == 1 || visited[y][x][ability + 1]) continue;

            q.push(make_tuple(y, x, cnt + 1, ability + 1));
            visited[y][x][ability + 1] = true;
          }
        }
        for (int i = 0; i < 4; i++) {
          int y = t_y + my[i];
          int x = t_x + mx[i];
          if (y < 0 || H <= y || x < 0 || W <= x) continue;
          if (grid[y][x] == 1 || visited[y][x][ability]) continue;

          q.push(make_tuple(y, x, cnt + 1, ability));
          visited[y][x][ability] = true;
        }
      }
    }
  }

  cout << -1;
}
