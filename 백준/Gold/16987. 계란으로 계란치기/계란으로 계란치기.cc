#include <iostream>

using namespace std;

pair<int, int> eggs[9];
int N, S, W;
int ans;

void bt(int curr) {
    if (curr == N) {
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (eggs[i].first <= 0) count++;
        }
        
        if (ans < count) ans = count;
        return;
    }

    if (eggs[curr].first <= 0) {
        bt(curr + 1);
        return;
    }
    
    bool flag = false;
    for (int i = 0; i < N; ++i) {
        if (eggs[i].first <= 0 || curr == i) continue;

        eggs[curr].first -= eggs[i].second;
        eggs[i].first -= eggs[curr].second;

        flag = true;
        bt(curr + 1);

        eggs[curr].first += eggs[i].second;
        eggs[i].first += eggs[curr].second;
    }

    if (!flag) bt(curr + 1);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> S >> W;
        eggs[i] = {S, W};
    }

    bt(0);

    cout << ans;
}
