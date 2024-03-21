#include <stdio.h>
#include <stdlib.h>

int N;
int board[16];
int cnt;

bool check(int row) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == board[row] || row - i == abs(board[row] - board[i])) {
            return false;
        }
    }
    return true;
}

void nqueen(int row) {
    if (row == N) {
        cnt++;
        return;
    }

    for (int col = 0; col < N; ++col) {
        board[row] = col;
        if (check(row)) {
            nqueen(row + 1);
        }
    }
}

int main() {
    scanf("%d", &N);
    nqueen(0);
    printf("%d", cnt);
}