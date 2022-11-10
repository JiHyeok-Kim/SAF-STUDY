#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int H, W, ans;
int white[55], red[55], blue[55];
string map[55];
int path[2];
int used[2];

void init() {
	ans = 21e8;
	for (int i = 0; i < 55; i++) {
		map[i] = "";
		white[i] = 0;
		red[i] = 0;
		blue[i] = 0;
	}
}

void input() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> map[i];
	}
}


void getAns() {
	int lineW = path[0];
	int lineB = path[1];
	int sum = 0;

	sum += white[lineW] + red[H - 1] - red[lineB] + blue[lineB] - blue[lineW];

	if (sum < ans) {
		ans = sum;
	}
}

void dfs(int lev, int start) {
	if (lev == 2) {
		getAns();
		return;
	}

	for (int i = start; i <= H - 2; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = i;
		dfs(lev + 1, i);
		path[lev] = 0;
		used[i] = 0;
	}

}

void solve() {
	// 각 행 깃발 색깔별 개수 부분합
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] != 'W') white[y]++;
			if (map[y][x] != 'B') blue[y]++;
			if (map[y][x] != 'R') red[y]++;
		}
		white[y + 1] = white[y];
		blue[y + 1] = blue[y];
		red[y + 1] = red[y];
	}

	dfs(0, 0);
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}