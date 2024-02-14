#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
char square[26][26];
bool visited[26][26];
queue<pair<int, int> > q;
vector<int> v;
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, -1, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> square[i];
  }

  char count = '0';
  int cnt2 = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (square[i][j] == '1' && !visited[i][j]) {
        int cnt = 1;
        cnt2++;
        count++;
        q.push(make_pair(i, j));
        square[i][j] = count;
        visited[i][j] = true;
        while (!q.empty()) {
          pair<int, int> p = q.front();
          q.pop();
          for (int k = 0; k < 4; ++k) {
            int y = p.first + my[k];
            int x = p.second + mx[k];

            if (y < 0 || N <= y || x < 0 || N <= x) continue;
            if (visited[y][x] || square[y][x] != '1') continue;
            cnt++;
            q.push(make_pair(y, x));
            square[y][x] = count;
            visited[y][x] = true;
          }
        }
        v.push_back(cnt);
      }
    }
  }
  cout << cnt2 << '\n';
  sort(v.begin(), v.end());
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << '\n';
  }
}