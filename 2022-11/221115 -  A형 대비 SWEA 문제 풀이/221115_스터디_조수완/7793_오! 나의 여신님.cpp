#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T, N, M, py, px, sy, sx;
char m[55][55];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int, int>> dv;

void bfs(int(*u)[55]) {
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < dv.size(); i++) {
        q.push({ 1,{dv[i].first, dv[i].second} });
        u[dv[i].first][dv[i].second] = 1;
    }

    while (!q.empty()) {
        pair<int, pair<int, int>> now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.second.first + dy[i];
            int nx = now.second.second + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
            if (m[ny][nx] == 'X' || m[ny][nx] == 'D')continue;
            if (u[ny][nx] <= now.first + 1) continue;
            u[ny][nx] = now.first + 1;
            q.push({ now.first + 1,{ny,nx} });
        }
    }
}
void simul(int y, int x, int s, int(*u)[55], int(*d)[55]) {
    queue<pair<int, pair<int, int>>> q;
    q.push({ 1,{y, x} });
    d[y][x] = 1;

    while (!q.empty()) {
        pair<int, pair<int, int>> now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.second.first + dy[i];
            int nx = now.second.second + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
            if (m[ny][nx] == 'X' || u[ny][nx] <= now.first + 1)continue;
            if (d[ny][nx] <= now.first + 1)continue;
            d[ny][nx] = now.first + 1;
            q.push({ now.first + 1,{ny,nx} });
        }
    }
}
void solve() {
    cin >> T; for (int t = 1; t <= T; t++) {
        cin >> N >> M;
        int u[55][55] = { 0 }, d[55][55] = { 0 };
        int(*pu)[55], (*pd)[55];
        dv.clear();
        for (int y = 0; y < N; y++)for (int x = 0; x < M; x++) {
            cin >> m[y][x];
            d[y][x] = 21e8;
            u[y][x] = 21e8;
            if (m[y][x] == 'D') { py = y; px = x; }
            if (m[y][x] == '*') { dv.push_back({ y,x }); }
            if (m[y][x] == 'S') { sy = y; sx = x; }
        }
        u[py][px] = 21e8, pu = u, pd = d;
        bfs(pu);
        simul(sy, sx, 1, pu, pd);
        if (d[py][px] == 21e8)cout << "#" << t << " GAME OVER\n";
        else cout << "#" << t << " " << d[py][px] - 1 << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    solve();
    return 0;
}