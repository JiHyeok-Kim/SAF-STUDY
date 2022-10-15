#include <iostream>
#include <vector>
using namespace std;
int map[110][110], N, score, result;
int drY[4] = { -1,0,1,0 };
int drX[4] = { 0,1,0,-1 };
int block[6][4] = {
    {0,0,0,0},
    {-1,-1,1,0},
    {1,-1,-1,2},
    {3,2,-1,-1},
    {-1,0,3,-1},
    {-1,-1,-1,-1}
};
vector<pair<int, int>> wormhole[11];
void init() {
    for (int i = 6; i < 11; i++)wormhole[i].clear();
    result = 0;
}
void input() {
    cin >> N;
    for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) {
        cin >> map[y][x];
        if (map[y][x] > 5) wormhole[map[y][x]].push_back({ y, x });
    }
}
void simulation(int sy, int sx, int sdir) {
    score = 0;
    int y = sy, x = sx, dir = sdir;
    while (1) {
        y += drY[dir];
        x += drX[dir];
        if (y < 0 || x < 0 || y >= N || x >= N) {
            score = score * 2 + 1;
            break;;
        }
        if (map[y][x] == -1) break;
        if (y == sy && x == sx) break;
        if (map[y][x] == 0) continue;
        if (map[y][x] > 5) {
            int tar = map[y][x];
            for (int i = 0; i < 2; i++) {
                if (wormhole[tar][i].first == y && wormhole[tar][i].second == x) continue;
                y = wormhole[tar][i].first;
                x = wormhole[tar][i].second;
                break;
            }
            continue;
        }
        if (map[y][x] > 0 && map[y][x] < 6) {
            dir = block[map[y][x]][dir];
            if (dir == -1) {
                score = score * 2 + 1;
                break;
            }
            score++;
        }
    }
    if (result < score) result = score;
}
void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        input();
        for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) {
            if (map[y][x] != 0)continue;
            for (int initDir = 0; initDir < 4; initDir++) simulation(y, x, initDir);
        }
        cout << "#" << t << " " << result << "\n";
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