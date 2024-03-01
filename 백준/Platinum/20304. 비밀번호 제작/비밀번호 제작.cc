#include <iostream>
#include <queue>

using namespace std;

int N, M;

int p[1000001];

bool visited[1000001];

int safe[1000001];

queue<int> q;

int bit_size = 1;

int max_cnt;

int main() {
  cin >> N >> M;

  int temp = N;
  while (temp / 2 != 0) {
    bit_size++;
    temp /= 2;
  }

  for (int i = 0; i < M; i++) {
    int passward;
    cin >> passward;

    p[i] = passward;
    visited[passward] = true;
    q.push(passward);
  }

  while (!q.empty()) {
    int num = q.front();
    q.pop();

    for (int i = 0; i < bit_size; i++) {
      int one = num ^ (1 << i);

      if (one <= N && !visited[one]) {
        safe[one] = safe[num] + 1;
        visited[one] = true;
        q.push(one);
      }
    }
  }
  for (int i = 0; i <= N; i++) {
    max_cnt = max(max_cnt, safe[i]);
  }

  cout << max_cnt << endl;
}