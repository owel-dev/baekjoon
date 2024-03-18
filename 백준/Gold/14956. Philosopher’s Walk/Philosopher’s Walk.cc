#include <iostream>

using namespace std;

int N, M;

pair<int, int> find(int n, int m) {
    if (n == 2) {
        switch (m) {
            case 0: return {1, 1};
            case 1: return {1, 2};
            case 2: return {2, 2};
            case 3: return {2, 1};
        }
    }

    int total = n * n;
    int quarter = total / 4;
    int quadrant = m / quarter;

    auto p = find(n / 2, m - quarter * quadrant);
    int x = p.first;
    int y = p.second;

    switch (quadrant) {
        case 0: return {y, x};
        case 1: return {x, y + n / 2};
        case 2: return {x + n / 2, y + n / 2};
        case 3: return {n + 1 - y, n / 2 + 1 - x};
    }
}

int main() {
    cin >> N >> M;

    auto p = find(N, M - 1);

    cout << p.first << " " << p.second;
}