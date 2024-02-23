#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int x, y, a, b;

vector<pair<int, int> > light[102][102];
queue<pair<int, int> > q;
bool visited[102][102];

int my[4] = {-1, 1, 0, 0};
int mx[4] = {0, 0, -1, 1};

bool on[102][102];

int cnt;

int main() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> x >> y >> a >> b;
    light[x][y].push_back({a, b});
  }
  q.push(make_pair(1, 1));
  visited[1][1] = true;
  on[1][1] = true;
  cnt++;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int now_y = p.first;
    int now_x = p.second;
      
    for (auto room : light[now_y][now_x]) {
      int room_y = room.first;
      int room_x = room.second;
      if (!on[room_y][room_x]) {
        on[room_y][room_x] = true;
        cnt++;

        for (int i = 0; i < 4; i++) {
          int visit_y = room_y + my[i];
          int visit_x = room_x + mx[i];

          if (visit_y < 1 || N < visit_y || visit_x < 1 || M < visit_x)
            continue;
          if (visited[visit_y][visit_x]) {
            q.push({visit_y, visit_x});
            break;
          }
        }
      }
    }

    for (int i = 0; i < 4; i++) {
      int ny = now_y + my[i];
      int nx = now_x + mx[i];

      if (ny < 1 || N < ny || nx < 1 || N < nx) continue;

      if (on[ny][nx] && !visited[ny][nx]) {
        q.push({ny, nx});
        visited[ny][nx] = true;
      }
    }
  }
  cout << cnt << endl;
}