#include <iostream>
#include <cstring>

using namespace std;

int K;

string gears[4];

int rotate_dir[4];

const int FORWARD = 1;
const int REVERSE = -1;
const int RIGHT = 2;
const int LEFT = 6;

int ans;

void gear_init() {
    for (auto &gear: gears) {
        cin >> gear;
    }
}

void left_check(int index, int dir) {
    if (index == 0) return;

    if (gears[index][LEFT] == gears[index - 1][RIGHT]) return;

    rotate_dir[index - 1] = -dir;
    left_check(index - 1, -dir);
}

void right_check(int index, int dir) {
    if (index == 3) return;

    if (gears[index][RIGHT] == gears[index + 1][LEFT]) return;

    rotate_dir[index + 1] = -dir;
    right_check(index + 1, -dir);
}

void rotate(int index, int dir) {
    string gear = gears[index];

    switch (dir) {
        case FORWARD:
            gears[index] = gear[7] + gear.substr(0, 7);
            break;
        case REVERSE:
            gears[index] = gear.substr(1, 7) + gear[0];
            break;
    }
}

int main() {
    gear_init();

    cin >> K;

    for (int i = 0; i < K; ++i) {
        int num, dir;
        cin >> num >> dir;
        num -= 1;

        memset(rotate_dir, 0, sizeof(int) * 4);
        rotate_dir[num] = dir;

        left_check(num, dir);
        right_check(num, dir);

        for (int j = 0; j < 4; ++j) {
            if (rotate_dir[j] != 0) {
                rotate(j, rotate_dir[j]);
            }
        }
    }

    int bin = 1;
    for (auto &gear: gears) {
        ans += (gear[0] - '0') * bin;
        bin *= 2;
    }

    cout << ans;
}
