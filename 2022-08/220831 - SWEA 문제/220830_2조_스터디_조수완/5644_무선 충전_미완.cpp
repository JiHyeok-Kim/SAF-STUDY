#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int idx;
    int val;
};
struct qNode {
    int y, x;
    int lev;
};
queue<qNode> q;
vector<Node> map[11][11];
int T, M, A, C, P;
int Alist[110], Blist[110];
int drY[5] = { 0,-1,0,1,0 };
int drX[5] = { 0,0,1,0,-1 };

void init() {
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 11; x++) {
            map[y][x].clear();
        }
    }
}
void setting() {
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 11; x++) {
            if (map[y][x].empty()) map[y][x].push_back({ 0,0 });
        }
    }
}
qNode getCoor(qNode now, int dr) {
    int ny = now.y + drY[dr];
    int nx = now.x + drX[dr];
    return { ny,nx };
}

void setMap(int sy, int sx, int idx, int c, int p) {
    int used[11][11] = { 0 };
    q.push({ sy,sx,0 });
    used[sy][sx] = 1;

    while (!q.empty()) {
        qNode now = q.front();
        q.pop();

        for (int i = 1; i < 5; i++) {
            int ny = now.y + drY[i];
            int nx = now.x + drX[i];
            int nLev = now.lev + 1;
            if (ny < 1 || nx < 1 || ny >= 11 || nx >= 11)continue;
            if (nLev == c + 1) continue;
            if (used[ny][nx] == 1)continue;
            used[ny][nx] = 1;
            q.push({ ny,nx,nLev });
            map[ny][nx].push_back({ idx,p });
        }
    }
}
int getP(int y1, int x1, int y2, int x2) {
    int maxi = -1;
    if (map[y1][x1].size() + map[y2][x2].size() > 2) {
        for (int i = 0; i < map[y1][x1].size(); i++) {
            for (int j = 0; j < map[y2][x2].size(); j++) {
                if (map[y1][x1][i].idx == map[y2][x2][j].idx) {
                    int temp = map[y1][x1][i].val;
                    maxi = max(maxi, temp);
                }
                else {
                    int temp = map[y1][x1][i].val + map[y2][x2][j].val;
                    maxi = max(maxi, temp);
                }
            }
        }
    }
    else {
        if (map[y1][x1][0].idx == map[y2][x2][0].idx) {
            maxi = max(maxi, map[y1][x1][0].val);
        }
        else maxi = max(maxi, map[y1][x1][0].val + map[y2][x2][0].val);
    }
    return maxi;
}


int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        cin >> M >> A;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < M; j++) {
                if (i == 0) cin >> Alist[j];
                if (i == 1) cin >> Blist[j];
            }
        }
        for (int i = 0; i < A; i++) {
            int y, x, c, p;
            cin >> y >> x >> c >> p;
            setMap(y, x, i + 1, c, p);
        }
        setting();
        int sum = 0;
        qNode Anow = { 1,1 };
        qNode Bnow = { 10,10 };
        /*if (!map[1][1].empty()) Asum += map[1][1][0].val;
        if (!map[10][10].empty()) Bsum += map[10][10][0].val;*/
        for (int times = 0; times <= M; times++) {
            sum += getP(Anow.y, Anow.x, Bnow.y, Bnow.x);
            if (times == M)break;
            Anow = getCoor(Anow, Alist[times]);
            Bnow = getCoor(Bnow, Blist[times]);
        }
        cout << "#" << t << " " << sum << '\n';
    }
    return 0;
}