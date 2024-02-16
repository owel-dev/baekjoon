#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[101][101];
queue<pair<int, int> > q;
int my[4] = {-1, 1, 0, 0};
int mx[4] = {0, 0, -1, 1};
int best = 0;
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  for (int rain = 0; rain <= 100; rain++) {
    int count = 0;
    bool visited[101][101] = {false};

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (arr[i][j] > rain && !visited[i][j]) {
          count++;
          q.push(make_pair(i, j));
          visited[i][j] = true;

          while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
              int y = p.first + my[i];
              int x = p.second + mx[i];

              if (y < 0 || N <= y || x < 0 || N <= x) continue;
              if (arr[y][x] <= rain || visited[y][x]) continue;

              q.push(make_pair(y, x));
              visited[y][x] = true;
            }
          }
        }
      }
    }
    if (count == 0) break;
    best = max(best, count);
  }

  cout << best << '\n';
}