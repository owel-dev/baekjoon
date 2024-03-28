#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int seq[9], ans[9];

void recv(int idx, int min) {
    if (idx == M) {
        for (int i = 0; i < M; ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    int dup_check = 0;
    for (int i = 0; i < N; ++i) {
        if (seq[i] != dup_check && min <= seq[i]) {
            dup_check = seq[i];
            ans[idx] = seq[i];
            recv(idx + 1, seq[i]);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        seq[i] = num;
    }
    sort(seq, seq + N);
    recv(0, 1);
}