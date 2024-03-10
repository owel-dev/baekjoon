#include<cstdio>

char buffer[1 << 20];
int idx, ridx;

static inline char read() {
    if (idx == ridx) {
        ridx = fread(buffer, 1, 1 << 20, stdin);
        idx = buffer[ridx] = 0;
    }
    return buffer[idx++];
}

static inline int readint() {
    int r = 0;
    bool n = 0;
    register char c = read();
    while (c < 33) c = read();
    if (c == '-') n = 1, c = read();
    while (c >= 48 && c <= 57) {
        r = r * 10 + (c & 15);
        c = read();
    }
    return n ? -r : r;
}

int N, p[2200][2200], res[3];

int numberOfPaper(int y, int x, int n) {
    if (n == 1) {
        res[p[y][x] + 1]++;
        return p[y][x];
    }
    bool isOne = 1;
    for (int i = 0; i < n; i += n / 3) {
        for (int j = 0; j < n; j += n / 3) {
            if (numberOfPaper(y + i, x + j, n / 3) != p[y][x]) {
                isOne = 0;
            }
        }
    }
    if (isOne) {
        res[p[y][x] + 1] -= 8;
        return p[y][x];
    }
    else return 2;
}

int main() {
    N = readint();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            p[i][j] = readint();
    numberOfPaper(0, 0, N);
    printf("%d\n%d\n%d", res[0], res[1], res[2]);
}