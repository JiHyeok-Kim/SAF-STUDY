#include <iostream>
#include <algorithm>
using namespace std;

char map[20][20];

int R, C;
int maxVal;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool visited[150] = { 0 };

void dfs(int y, int x, int val) {
	maxVal = max(maxVal, val);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if (visited[map[ny][nx]]) continue;
		visited[map[ny][nx]] = true;
		dfs(ny, nx, val + 1);
		visited[map[ny][nx]] = false;
	}
}

void solve() {
	visited[map[0][0]] = true;
	dfs(0, 0, 1);
	visited[map[0][0]] = false;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> R >> C;
		maxVal = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> map[i][j];
			}
		}

		solve();

		cout << "#" << t << " " << maxVal << '\n';
	}
	return 0;
}