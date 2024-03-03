#include <iostream>

using namespace std;

int N;

void hanoi(int n, int start, int bypass, int to) {
  if (n == 1) {
    cout << start << " " << to << '\n';
  } else {
    hanoi(n - 1, start, to, bypass);
    cout << start << " " << to << '\n';
    hanoi(n - 1, bypass, start, to);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  cout << (1 << N) - 1 << '\n';
  hanoi(N, 1, 2, 3);
}