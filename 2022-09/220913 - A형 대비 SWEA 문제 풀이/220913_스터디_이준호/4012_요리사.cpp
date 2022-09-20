#include <iostream>
#include <vector>
using namespace std;

int n;
int map[16][16];
int used[16];
int mini = 21e8;

void input() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }
}

void run2() {
    vector<int> tong1;
    vector<int> tong2;

    int food1 = 0;
    int food2 = 0;

    for (int i = 0; i < n; i++) {
        if (used[i] == 1) tong1.push_back(i);
        else tong2.push_back(i);
    }

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (i == j) continue;
            food1 += map[tong1[i]][tong1[j]];
            food2 += map[tong2[i]][tong2[j]];
        }
    }

    mini = min(mini, abs(food1 - food2));
    return;
}

void run(int lev, int start) {
    if (lev == n / 2) {
        run2();
        return;
    }
    for (int i = start; i < n; i++) {
        if (used[i] == 1) continue;
        used[i] = 1;
        run(lev + 1, i + 1);
        used[i] = 0;
    }
}


int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int tcCnt;
    cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++) {
        cin >> n;
        mini = 21e8;

        input();
        run(0, 0);

        int ans = 0;
        cout << "#" << tc << " " << mini << "\n";
    }

    return 0;
}