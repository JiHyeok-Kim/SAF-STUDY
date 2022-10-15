#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, used[22][22];
int map[22][22], N, maxi = -1;
int drY[4] = { 1,1,-1,-1 };
int drX[4] = { 1,-1,-1,1 };

int isPossible(vector<int> path, int pathLen) {
    int dat[1000] = { 0 };
    for (int i = 0; i < pathLen; i++) {
        dat[path[i]]++;
        if (dat[path[i]] > 1) return 0;
    }
    return 1;
}


void getCost(int ty, int tx, int y, int x, int lev, vector<int> path) {
    if (lev == 4) return;

    for (int i = 1; i <= N ; i++) {
        int ny = y + i * drY[lev];
        int nx = x + i * drX[lev];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (lev == 3) {
            if (ny == ty && nx == tx) {
                int sizeLen = path.size();
                if (isPossible(path, sizeLen)) maxi = max(maxi, sizeLen);
                int a = 1;
            }
        }
        path.push_back(map[ny][nx]);
        if (!isPossible(path, path.size())) return;
        getCost(ty, tx, ny, nx, lev + 1, path);
    }
}


int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        maxi = -1;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> map[y][x];
            }
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                vector<int> path = { map[y][x] };
                getCost(y, x, y, x, 0, path);
            }
        }
        cout << "#" << t << " " << maxi << '\n';
    }
    return 0;
}