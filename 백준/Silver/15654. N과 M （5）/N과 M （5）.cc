#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int seq[9], ans[9], visited[9];

void recv(int idx) {
    if (idx == M) {
        for (int i = 0; i < M; ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!visited[i]){
            visited[i] = true;
            ans[idx] = seq[i];
            recv(idx + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }
    sort(seq, seq + N);
    recv(0);
}