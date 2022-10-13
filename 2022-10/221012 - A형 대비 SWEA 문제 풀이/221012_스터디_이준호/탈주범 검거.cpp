#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M, R, C, L;
int map[51][51];
int used[51][51];

int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };

struct Node {
    int y, x;
    int lev;
};
queue<Node> q;


int fp() {
    q.push({ R,C,1 });
    used[R][C] = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (now.lev == L) {
            break;
        }
        if (map[now.y][now.x] == 1) {
            for (int i = 0; i < 4; i++) {
                int ny = now.y + ditY[i];
                int nx = now.x + ditX[i];
                if (map[ny][nx] == 0) continue;
                if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)) continue;
                if (i == 1 && (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)) continue;
                if (i == 2 && (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)) continue;
                if (i == 3 && (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)) continue;
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (used[ny][nx] >= 1) continue;
                used[ny][nx] = map[ny][nx];
                q.push({ ny,nx, now.lev + 1 });
            }
        }
        else if (map[now.y][now.x] == 2) {
            for (int i = 0; i < 2; i++) {
                int ny = now.y + ditY[i];
                int nx = now.x + ditX[i];
                if (map[ny][nx] == 0 || map[ny][nx] == 3) continue;
                if (i == 0 && (map[ny][nx] == 4 || map[ny][nx] == 7)) continue;
                if (i == 1 && (map[ny][nx] == 5 || map[ny][nx] == 6)) continue;
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (used[ny][nx] >= 1) continue;
                used[ny][nx] = map[ny][nx];
                q.push({ ny,nx, now.lev + 1 });
            }
        }
        else if (map[now.y][now.x] == 3) {
            for (int i = 2; i < 4; i++) {
                int ny = now.y + ditY[i];
                int nx = now.x + ditX[i];
                if (map[ny][nx] == 0 || map[ny][nx] == 2) continue;
                if (i == 2 && (map[ny][nx] == 6 || map[ny][nx] == 7)) continue;
                if (i == 3 && (map[ny][nx] == 4 || map[ny][nx] == 5)) continue;
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (used[ny][nx] >= 1) continue;
                used[ny][nx] = map[ny][nx];
                q.push({ ny,nx, now.lev + 1 });
            }
        }
        else if (map[now.y][now.x] == 4) {
            for (int i = 0; i < 4; i++) {
                if (i == 1 || i == 2) continue;
                int ny = now.y + ditY[i];
                int nx = now.x + ditX[i];
                if (map[ny][nx] == 0 || map[ny][nx] == 4) continue;
                if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 7)) continue;
                if (i == 3 && (map[ny][nx] == 2 || map[ny][nx] == 5)) continue;
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (used[ny][nx] >= 1) continue;
                used[ny][nx] = map[ny][nx];
                q.push({ ny,nx, now.lev + 1 });
            }
        }
        else if (map[now.y][now.x] == 5) {
            for (int i = 1; i < 4; i++) {
                if (i == 2) continue;
                int ny = now.y + ditY[i];
                int nx = now.x + ditX[i];
                if (map[ny][nx] == 0 || map[ny][nx] == 5) continue;
                if (i == 1 && (map[ny][nx] == 3 || map[ny][nx] == 6)) continue;
                if (i == 3 && (map[ny][nx] == 2 || map[ny][nx] == 4)) continue;
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (used[ny][nx] >= 1) continue;
                used[ny][nx] = map[ny][nx];
                q.push({ ny,nx, now.lev + 1 });
            }
        }
        else if (map[now.y][now.x] == 6) {
            for (int i = 1; i < 3; i++) {
                int ny = now.y + ditY[i];
                int nx = now.x + ditX[i];
                if (map[ny][nx] == 0 || map[ny][nx] == 6) continue;
                if (i == 1 && (map[ny][nx] == 3 || map[ny][nx] == 5)) continue;
                if (i == 2 && (map[ny][nx] == 2 || map[ny][nx] == 7)) continue;
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (used[ny][nx] >= 1) continue;
                used[ny][nx] = map[ny][nx];
                q.push({ ny,nx, now.lev + 1 });
            }
        }
        else if (map[now.y][now.x] == 7) {
            for (int i = 0; i < 3; i++) {
                if (i == 1) continue;
                int ny = now.y + ditY[i];
                int nx = now.x + ditX[i];
                if (map[ny][nx] == 0 || map[ny][nx] == 7) continue;
                if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 4)) continue;
                if (i == 2 && (map[ny][nx] == 2 || map[ny][nx] == 6)) continue;
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (used[ny][nx] >= 1) continue;
                used[ny][nx] = map[ny][nx];
                q.push({ ny,nx, now.lev + 1 });
            }
        }
    }

    int cnt = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (used[y][x] >= 1) cnt++;
        }
    }
    return cnt;
}

int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    int tcCnt;
    cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++) {
        cin >> N >> M >> R >> C >> L;

        memset(map, 0, sizeof(map));
        memset(used, 0, sizeof(used));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> map[y][x];
            }
        }

        int ans = fp();
        cout << "#" << tc << " " << ans << "\n";
        while (!q.empty()) {
            q.pop();
        }
    }
}