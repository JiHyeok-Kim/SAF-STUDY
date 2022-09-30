#include <iostream>
#include <cstring>
using namespace std;

int map[9][9];
int dat[10];

bool garo() {
    for (int y = 0; y < 9; y++) {
        memset(dat, 0, sizeof(dat));
        for (int x = 0; x < 9; x++) {
            dat[map[y][x]]++;
        }

        for (int i = 1; i < 10; i++) {
            if (dat[i] != 1) return 0;
        }
    }
    return 1;
}

bool sero() {
    for (int x = 0; x < 9; x++) {
        memset(dat, 0, sizeof(dat));
        for (int y = 0; y < 9; y++) {
            dat[map[y][x]]++;
        }

        for (int i = 1; i < 10; i++) {
            if (dat[i] != 1) return 0;
        }
    }
    return 1;
}

bool box() {
    for (int y = 0; y < 9; y += 3) {
        for (int x = 0; x < 9; x += 3) {

            memset(dat, 0, sizeof(dat));
            for (int i = y; i < y + 3; i++) {
                for (int j = x; j < x + 3; j++) {
                    dat[map[i][j]]++;
                }
            }
            for (int k = 1; k < 10; k++) {
                if (dat[k] != 1) return 0;
            }

        }
    }
}

int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int tcCnt;
    cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++) {
        int flag = 0;
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                cin >> map[y][x];
            }
        }

        if (garo() == 0) flag = 1;
        else if (sero() == 0) flag = 1;
        else if (box() == 0) flag = 1;

        if (flag == 1) {
            cout << "#" << tc << " " << 0 << "\n";
        }
        else cout << "#" << tc << " " << 1 << "\n";
    }

    return 0;
}