#include <iostream>

using namespace std;

size_t A, B, C;

int recv(size_t a, size_t b, size_t c) {
  if (b == 0) return 1;

  if (b % 2 == 1) {
    return (a * recv(a, b - 1, c)) % c;
  } else {
    size_t half = recv(a, b / 2, c);

    return (half * half) % c;
  }
}
int main() {
  cin >> A >> B >> C;

  cout << recv(A, B, C) << endl;
}