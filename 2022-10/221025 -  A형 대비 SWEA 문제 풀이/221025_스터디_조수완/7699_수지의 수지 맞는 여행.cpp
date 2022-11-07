#include <iostream>
#include <queue>
using namespace std;
int R, C, result;
char island[22][22];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };

void input() {
	result = 0;
	cin >> R >> C;
	for (int y = 0; y < R; y++)for (int x = 0; x < C; x++) cin >> island[y][x];
}
void dfs(int cnt, int y, int x, int used[140]) {
	result = max(result, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = y + drY[i];
		int nx = x + drX[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if (used[island[ny][nx]] == 1)continue;
		used[island[ny][nx]] = 1;
		dfs(cnt + 1, ny, nx, used);
		used[island[ny][nx]] = 0;
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		int used[140] = { 0 };
		used[island[0][0]] = 1;
		dfs(1, 0, 0, used);
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