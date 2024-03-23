#include <stdio.h>
#include <vector>

int N, M;

int seq[9];

void recv(int idx, int end) {
    if (idx == M) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", seq[i]);
        }
        printf("\n");
        return ;
    }

    for (int num = end; num <= N; ++num) {
        seq[idx] = num;
        recv(idx + 1, num + 1);
    }

}

int main() {
    scanf("%d %d", &N, &M);
    recv(0, 1);
}