#include <stdio.h>

int N, S;
int seq[21];
int cnt;

void recv(int idx, int sum) {
    if (idx == N) {
        return;
    }

    if (sum + seq[idx] == S) {
        cnt++;
    }

    recv(idx + 1, sum);
    recv(idx + 1, sum + seq[idx]);
}

int main() {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; ++i) {
        scanf("%d", seq + i);
    }

    recv(0, 0);

    printf("%d", cnt);
}