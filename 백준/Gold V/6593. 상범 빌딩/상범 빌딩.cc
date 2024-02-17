#include <stdio.h>

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int mz[6] = {0, 0, 0, 0, 1, -1};
int my[6] = {-1, 1, 0, 0, 0, 0};
int mx[6] = {0, 0, -1, 1, 0, 0};
queue<tuple<int, int, int> > q;
tuple<int, int, int> e_position;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (true) {
    char qube[31][31][31] = {0};
    bool visited[31][31][31] = {0};
    int move_time[31][31][31] = {0};
    int L, R, C;

    cin >> L >> R >> C;
    if (L == 0 && R == 0 && C == 0) break;
    for (int i = 0; i < L; i++) {
      for (int j = 0; j < R; j++) {
        for (int k = 0; k < C; k++) {
          cin >> qube[i][j][k];
          if (qube[i][j][k] == 'E') {
            e_position = make_tuple(i, j, k);
          }
        }
      }
    }

    for (int i = 0; i < L; i++) {
      for (int j = 0; j < R; j++) {
        for (int k = 0; k < C; k++) {
          if (qube[i][j][k] == 'S') {
            q.push(make_tuple(i, j, k));
            qube[i][j][k] = '*';
            visited[i][j][k] = true;

            while (!q.empty()) {
              tuple<int, int, int> t = q.front();
              q.pop();

              for (int i = 0; i < 6; i++) {
                int tuple_1 = get<0>(t);
                int tuple_2 = get<1>(t);
                int tuple_3 = get<2>(t);

                int z = tuple_1 + mz[i];
                int y = tuple_2 + my[i];
                int x = tuple_3 + mx[i];

                if (z < 0 || L <= z || y < 0 || R <= y || x < 0 || C <= x)
                  continue;
                if (visited[z][y][x] || qube[z][y][x] == '#') continue;

                q.push(make_tuple(z, y, x));
                visited[z][y][x] = true;
                qube[z][y][x] = '*';
                move_time[z][y][x] = move_time[tuple_1][tuple_2][tuple_3] + 1;
              }
            }
          }
        }
      }
    }

    int e_z = get<0>(e_position);
    int e_y = get<1>(e_position);
    int e_x = get<2>(e_position);

    if (qube[e_z][e_y][e_x] == 'E') cout << "Trapped!" << '\n';
    else
      cout << "Escaped in " << move_time[e_z][e_y][e_x] << " minute(s)."
           << '\n';
  }
}