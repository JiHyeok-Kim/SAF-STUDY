#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, W, H, result, map[10][20][20];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
void input() {
	result = 21e8;
	cin >> N >> W >> H;
	for (int y = 0; y < H; y++) for (int x = 0; x < W; x++) cin >> map[0][y][x];
}
int getCnt(int lev) {
	int cnt = 0;
	for (int y = 0; y < H; y++)for (int x = 0; x < W; x++)if (map[lev][y][x] != 0)cnt++;
	return cnt;
}
void setMap(int lev) {
	for (int x = 0; x < W; x++)for (int y = H-1; y >= 0; y--) {
		if (map[lev][y][x] == 0)continue;
		for (int i = 1; i < H; i++) {
			if (y + i >= H) break;
			if (map[lev][y + i][x] != 0) break;
			swap(map[lev][y + i - 1][x], map[lev][y + i][x]);
		}
	}
}
void boom(int sy,int sx,int lev) {
	if (map[lev][sy][sx] == 0) return;
	map[lev][sy][sx] = 0;
	for (int i = 1; i <= map[lev - 1][sy][sx]-1; i++) {
		for (int j = 0; j < 4; j++) {
			int ny = sy + i * drY[j];
			int nx = sx + i * drX[j];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W)continue;
			if (map[lev][ny][nx] == 0) continue;
			boom(ny, nx, lev);
		}
	}
}
void simulation(int lev, int tar) {
	for (int y = 0; y < H; y++) {
		if (map[lev][y][tar] == 0) continue;
		boom(y, tar,lev);
		break;
	}
}
void findDropPoint(int lev) {
	if (lev == N + 1) {
		int cnt = getCnt(lev - 1);
		if (result > cnt) result = cnt;
		return;
	}
	for (int p = 0; p < W; p++) {
		memcpy(map[lev], map[lev - 1], sizeof(map[lev - 1]));
		simulation(lev, p);
		setMap(lev);
		findDropPoint(lev + 1);
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		findDropPoint(1);
		cout << "#" << t << " " << result << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}