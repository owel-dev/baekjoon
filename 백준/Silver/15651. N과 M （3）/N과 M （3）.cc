#include <stdio.h>

int N, M;
int seq[8];

void recv(int idx) {
    if (idx == M) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", seq[i]);
        }
        putchar('\n');
        return;
    }

    for (int num = 1; num <= N; ++num) {
        seq[idx] = num;
        recv(idx + 1);
    }
}

int main(){
    scanf("%d %d", &N, &M);
    recv(0);
}