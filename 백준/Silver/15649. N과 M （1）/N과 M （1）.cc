#include <iostream>
using namespace std;
int N, M;
bool visited[9];
int sequence[9];

void recv(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i) {
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int num = 1; num <= N; ++num) {
        if (!visited[num]) {
            visited[num] = true;
            sequence[cnt] = num;
            recv(cnt + 1);
            visited[num] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    recv(0);
}