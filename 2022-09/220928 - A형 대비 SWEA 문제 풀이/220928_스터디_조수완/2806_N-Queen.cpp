#include <iostream>
using namespace std;
int drY[2] = { 1,1 };
int drX[2] = { -1,1 };
int usedLev[10];
int used[11][11];
int N, result;
void init() {
    result = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            used[y][x] = 0;
        }
        usedLev[y] = 0;
    }
}
void setUsed(int ty, int tx, int tar) {
    used[ty][tx] += tar;
    int py = ty, px = tx;
    for (int i = 1; i <= N; i++) {
        int flag = 0;
        for (int j = 0; j < 2; j++) {
            int ny = py + i * drY[j];
            int nx = px + i * drX[j];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
                flag++;
                continue;
            }
            used[ny][nx] += tar;
        }
        if (flag == 2) break;
    }
}
void solution(int lev) {
    if (lev == N) {
        result++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (usedLev[i] == 1)continue;
        if (used[lev][i] >= 1)continue;
        usedLev[i] = 1;
        setUsed(lev, i, 1);
        solution(lev + 1);
        setUsed(lev, i, -1);
        usedLev[i] = 0;
    }
}
void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        init();
        solution(0);
        cout << "#" << t << " " << result << "\n";
    }
}
int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    solve();
    return 0;
}