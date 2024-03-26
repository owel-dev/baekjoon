#include <iostream>

using namespace std;

int N, M;

int seq[9];

void recv(int idx, int start) {
    if (idx == M) {
        for (int i = 0; i < M; ++i) {
            cout << seq[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int num = start; num <= N; ++num) {
        seq[idx] = num;
        recv(idx + 1, num);
    }
}

int main() {
    cin >> N >> M;
    recv(0, 1);
}