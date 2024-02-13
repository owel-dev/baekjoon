#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N, K;
int **arr;
queue<pair<int, int> > q;
vector<int> v;
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, -1, 1};
int repeat = 0, cnt = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> M >> N >> K;

  arr = new int *[M];

  for (int i = 0; i < M; ++i) {
    arr[i] = new int[N];
  }

  for (int i = 0; i < K; ++i) {
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = y1; i < y2; ++i) {
      for (int j = x1; j < x2; ++j) {
        arr[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (arr[i][j] == 0) {
        q.push(make_pair(i, j));
        arr[i][j] = 2;

        repeat++;
        cnt = 0;
        while (!q.empty()) {
          pair<int, int> p = q.front();
          q.pop();
          cnt++;

          for (int i = 0; i < 4; i++) {
            int y = p.first + my[i];
            int x = p.second + mx[i];
            if (y < 0 || M <= y || x < 0 || N <= x) continue;
            if (arr[y][x] != 0) continue;

            q.push(make_pair(y, x));
            arr[y][x] = 2;
          }
        }
        v.push_back(cnt);
      }
    }
  }

  cout << repeat << '\n';

  sort(v.begin(), v.end());
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
  }
  cout << '\n';
}