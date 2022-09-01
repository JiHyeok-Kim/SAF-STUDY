#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int tcCnt, N;
int ans, cntCore, sum, maxCnt, mini;

int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };

struct Node {
    int y; int x;
};
vector<Node> core;

void input(int map[12][12]) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }
}
void inputCore(int map[12][12]) {
    for (int y = 1; y < N - 1; y++) {
        for (int x = 1; x < N - 1; x++) {
            if (map[y][x] == 1) {
                core.push_back({ y,x });
            }
        }
    }
}

void dfs(int lev, int sum, int map[12][12], int cntCore) {
    if (lev == core.size()) {
        if (maxCnt == cntCore) ans = min(ans, sum);
        if (maxCnt < cntCore ) {
            maxCnt = cntCore;
            ans = sum;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int flag = 0;
        int a = core[lev].y;
        int b = core[lev].x;
        int back = 0;
        int cantGo = 0;
        for (int j = 1; j < N; j++) {
            int ny = a + (ditY[i] * j);
            int nx = b + (ditX[i] * j);
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            {
                back = j; break;
            }

            if (map[ny][nx] != 0) { flag = 1; cantGo = j; break; }
            map[ny][nx] = 2;
            flag = 2;
        }

        if (flag == 1) {
            for (int j = 1; j < cantGo; j++) {
                int ny = a + (ditY[i] * j);
                int nx = b + (ditX[i] * j);
                map[ny][nx] = 0;
            }
        }
        if (flag == 2) {
            dfs(lev + 1, sum + back - 1, map, cntCore + 1);
        }
        for (int j = 1; j < back; j++) {
            int ny = a + (ditY[i] * j);
            int nx = b + (ditX[i] * j);
            map[ny][nx] = 0;
        }
    }
}

int main()
{
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> tcCnt;

    int map[12][12];
    for (int tc = 1; tc <= tcCnt; tc++) {
        memset(map, 0, sizeof(map));
        core.clear();
        maxCnt = -1;
        mini = 21e8;
        cin >> N; 
        input(map); inputCore(map);

        cntCore = 0;
        sum = 0;
        ans = 999;

        dfs(0, sum, map, cntCore);

        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}