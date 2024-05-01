#include <iostream>

using namespace std;

pair<int, int> eggs[9];
int N, S, W;
bool visited[9];
int sequence[9];
int ans;

void bt(int curr) {
    // cout << endl;
    // cout << "bt(curr) " << curr << endl;
    // for (int j = 0; j < N; ++j) {
    //     cout << curr << ' ' << eggs[j].first << ' ' << eggs[j].second << endl;
    // }

    if (curr == N) {
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (eggs[i].first <= 0) count++;
        }
        // cout << "count: " << count << endl;
        if (ans < count) ans = count;
        return;
    }

    if (eggs[curr].first <= 0) {
        // cout << "curr is broken" << endl;
        bt(curr + 1);

        return;
    }
    bool flag = false;
    for (int i = 0; i < N; ++i) {
        if (eggs[i].first <= 0 || curr == i) continue;

        // cout << "egg pounch - curr: " << curr << ", i: " << i << endl;

        eggs[curr].first -= eggs[i].second;
        eggs[i].first -= eggs[curr].second;

        flag = true;
        bt(curr + 1);

        eggs[curr].first += eggs[i].second;
        eggs[i].first += eggs[curr].second;
    }

    if (!flag) bt(curr + 1);

    if (curr == N - 1) {
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (eggs[i].first <= 0) count++;
        }
        // cout << "count: " << count << endl;
        if (ans < count) ans = count;
    }

}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> S >> W;
        eggs[i] = {S, W};
    }

    bt(0);

    // for (int i = 0; i < N; ++i) {
    //     cout << eggs[i].first << ' ' << eggs[i].second << endl;
    // }

    cout << ans;
}
