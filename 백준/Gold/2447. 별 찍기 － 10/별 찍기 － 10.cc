#include <iostream>
#include <vector>

using namespace std;

int N;

vector<string> star(int size) {
    vector<string> ret;

    if (size == 1) {
        ret.emplace_back("*");
        return ret;
    }

    vector<string> sub = star(size / 3);
    
    for (int part = 0; part < 3; ++part) {
        for (const string &s: sub) {
            if (part == 1) {
                string blank(size/3, ' ');
                ret.emplace_back(s + blank + s);
            } else {
                ret.emplace_back(s + s + s);
            }

        }

    }

    return ret;
}

int main() {
    cin >> N;

    vector<string> v = star(N);
    for (const auto &line: v) {
        cout << line << endl;
    }
}