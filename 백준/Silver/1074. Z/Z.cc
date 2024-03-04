#include <iostream>

using namespace std;

int N, r, c;

int num;

void recv(int y, int x, int size) {
  if (y == r && x == c) {
    cout << num << endl;
    return;
  }

  if (y <= r && r < y + size && x <= c && c < x + size) {
    recv(y, x, size / 2);
    recv(y, x + size / 2, size / 2);
    recv(y + size / 2, x, size / 2);
    recv(y + size / 2, x + size / 2, size / 2);
  } else {
    num += size * size;
  }
}

int main() {
  cin >> N >> r >> c;

  recv(0, 0, (1 << N));
}
