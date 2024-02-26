#include <cctype>
#include <iostream>
#include <queue>

using namespace std;

int c;
int my[4] = {-1, 1, 0, 0};
int mx[4] = {0, 0, -1, 1};
int main() {
  cin >> c;

  for (int i = 0; i < c; i++) {
    int h, w;
    string key;
    bool keys[1000] = {};
    char grid[102][102] = {};
    bool visited[101][101] = {};
    queue<pair<int, int> > q;
    queue<pair<int, int> > fq[150];
    int cnt = 0;

    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cin >> grid[i][j];
      }
    }

    cin >> key;

    if (key != "0") {
      for (char c : key) {
        keys[tolower(c)] = true;
      }
    }

    q.push({0, 0});
    visited[0][0] = true;
    grid[0][0] = 'O';
    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();

      int y = p.first;
      int x = p.second;
      for (int i = 0; i < 4; i++) {
        int ny = y + my[i];
        int nx = x + mx[i];

        if (ny < 0 || h + 1 < ny || nx < 0 || w + 1 < nx) continue;
        if (grid[ny][nx] == '*' || visited[ny][nx]) continue;

        char np = grid[ny][nx];

        if (isupper(np)) {
          if (keys[tolower(np)]) {
            q.push({ny, nx});
            visited[ny][nx] = true;
          } else {
            fq[np].push({ny, nx});
            visited[ny][nx] = true;
          }
        } else if (islower(np)) {
          keys[np] = true;

          q.push({ny, nx});
          visited[ny][nx] = true;
          while (!fq[toupper(np)].empty()) {
            pair<int, int> fp = fq[toupper(np)].front();
            fq[toupper(np)].pop();

            q.push({fp.first, fp.second});
          }
        } else {
          if (np == '$') cnt++;
          q.push({ny, nx});
          visited[ny][nx] = true;
        }
      }
    }

    cout << cnt << endl;
  }
}