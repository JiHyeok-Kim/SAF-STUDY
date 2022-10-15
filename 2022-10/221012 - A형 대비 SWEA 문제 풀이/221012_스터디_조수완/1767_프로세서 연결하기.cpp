#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int y, x;
};
vector<Node> cell;
int N, map[13][13];
int mini = 21e8, maxCnt = -1;
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };

void dfs(int lev, int sum, int tempMap[13][13], int flag, int cnt) {
    if (lev == cell.size()) {
        if(maxCnt == cnt) mini = min(mini, sum);
        if (maxCnt < cnt) {
            maxCnt = cnt;
            mini = sum;
        }
        return;
    }
    int flag1 = 0;
    for (int i = 0; i < 4; i++) {
        int k = 0;
        for (int j = 1; j <= 12; j++) {
            int ny = cell[lev].y + drY[i] * j;
            int nx = cell[lev].x + drX[i] * j;
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
                k = j;
                break;
            }
            if (tempMap[ny][nx] == 2) break;
            if (tempMap[ny][nx] == 1) {
                flag1++;
                break;
            }
        }
        for (int j = 1; j < k; j++) {
            int ny = cell[lev].y + drY[i] * j;
            int nx = cell[lev].x + drX[i] * j;
            tempMap[ny][nx] = 2;
        }
        if (k != 0) dfs(lev + 1, sum + k - 1, tempMap, flag, cnt + 1);
        if (k == 0 && flag1 == 4) dfs(lev + 1, sum, tempMap, flag, cnt);
        if (flag != 4 && flag == 1) dfs(lev + 1, sum, tempMap, 0, cnt);
        for (int j = 1; j < k; j++) {
            int ny = cell[lev].y + drY[i] * j;
            int nx = cell[lev].x + drX[i] * j;
            tempMap[ny][nx] = 0;
        }
    }
}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cell.clear();
        mini = 21e8;
        maxCnt = -1;
        cin >> N;
        int tempMap[13][13] = { 0 };
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> map[y][x];
                tempMap[y][x] = map[y][x];
                if (map[y][x] == 0) continue;
                if (y == 0 || x == 0 || y == N - 1 || x == N - 1) continue;
                cell.push_back({ y,x });
            }
        }
        dfs(0, 0, tempMap, 1,0);
        cout << "#" << t << " " << mini << "\n";
    }
    return 0;
}