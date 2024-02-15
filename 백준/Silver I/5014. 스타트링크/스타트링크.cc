#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int arr[1000002];
bool visited[1000002];

queue<int> q;
int main() {
  cin >> F >> S >> G >> U >> D;
  q.push(S);
  visited[S] = true;

  while (!q.empty()) {
    int stair = q.front();
    q.pop();
    int up = stair + U;
    int down = stair - D;
    if (up <= F && !visited[up]) {
      q.push(up);
      arr[up] = arr[stair] + 1;
      visited[up] = true;
    }
    if (0 < down && !visited[down]) {
      q.push(down);
      arr[down] = arr[stair] + 1;
      visited[down] = true;
    }
  }

  if (visited[G]) {
    cout << arr[G];
  } else {
    cout << "use the stairs";
  }
}