#include <iostream>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;

int line[100001];
int pre[100001];

int N, K;
queue<int> q;

int mx[3] = {-1, 1, 0};

stack<int> s;

int main() {
  cin >> N >> K;
  if (N == K) {
    cout << 0 << '\n';
    cout << N << '\n';
    return 0;
  }

  q.push(N);
  while (!q.empty()) {
    int dot = q.front();
    q.pop();

    if (dot == K) {
      cout << line[dot] << endl;
      s.push(K);
      for (int i = dot; i != N; i = pre[i]) s.push(pre[i]);
      while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
      }
      cout << '\n';
      return 0;
    }

    for (int i = 0; i < 3; ++i) {
      int x = dot + mx[i];
      if (i == 2) x = dot * 2;

      if (x < 0 || 100001 <= x || line[x] != 0) continue;
      line[x] = line[dot] + 1;
      pre[x] = dot;
      q.push(x);
    }
  }
}