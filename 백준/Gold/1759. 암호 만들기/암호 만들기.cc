#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char arr[16], pw[16];

void recv(int idx, int min) {
    if (idx == L) {
        int vowel_count = 0;
        for (int i = 0; i < L; ++i) {
            if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u') {
                vowel_count++;
            }
        }

        if (1 <= vowel_count && 2 <= L - vowel_count) {
            for (int i = 0; i < L; ++i) {
                cout << pw[i];
            }
            cout << '\n';
        }

        return;
    }

    for (int i = min; i < C; ++i) {
        pw[idx] = arr[i];
        recv(idx + 1, i + 1);
    }
}


int main() {
    cin >> L >> C;
    for (int i = 0; i < C; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + C);

    recv(0, 0);
}