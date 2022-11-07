#include <iostream>
using namespace std;

int map[10][25];
int memo[1<<10][25];

int H, W;
int maxVal;

void init() {
	cin >> H >> W;
	maxVal = 0;

	for (int i = 0; i < 1 << H; ++i) {
		for (int j = 0; j < W; ++j) {
			memo[i][j] = -1;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
}

bool check(int y, int x) {
	if (y >= H - 1) return false;
	if (x > W - 1) return false;
	if (map[y][x] == 1 || map[y][x + 1] == 1 || map[y + 1][x] == 1 || map[y + 1][x + 1] == 1) return false;

	return true;
}

void setUsing(int y, int x) {
	map[y][x] = 1;
	map[y + 1][x] = 1;
	map[y][x + 1] = 1;
	map[y + 1][x + 1] = 1;
}

void returnSet(int y, int x) {
	map[y][x] = 0;
	map[y + 1][x] = 0;
	map[y][x + 1] = 0;
	map[y + 1][x + 1] = 0;
}

void solve(int y, int x, int val) {
	if (y >= H - 1) {
		y = 0;
		x++;
	}

	if (x >= W - 1) {
		if (val > maxVal) maxVal = val;
		return;
	}

	if (y == 0) {
		int idx = 0;
		for (int i = 0; i < H; i++) {
			idx |= (map[i][x] << i);
		}
		if (memo[idx][x] >= val) {
			return;
		}
		else memo[idx][x] = val;
	}

	if (check(y, x)) {
		setUsing(y, x);
		solve(y + 2, x, val + 1);
		returnSet(y, x);
	}
	solve(y + 1, x, val);
}


int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();

		solve(0,0,0);


		cout << "#" << t << " " << maxVal << '\n';
	}
	return 0;
}