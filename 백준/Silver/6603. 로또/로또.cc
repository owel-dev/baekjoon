#include <iostream>

using namespace std;

int K, S[14], ans[14];

void recv(int a_idx, int s_idx) {
    if (a_idx == 6) {
        for (int i = 0; i < 6; ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = s_idx; i < K; ++i) {
        if (a_idx == 0 && K - s_idx < 6) {
            return ;
        }
        ans[a_idx] = S[i];
        recv(a_idx + 1, i + 1);
    }
}

int main() {
    while (true) {
        cin >> K;
        if (K == 0) return 0;
        for (int i = 0; i < K; ++i) {
            cin >> S[i];
        }
        recv(0, 0);
        cout << '\n';
    }
}