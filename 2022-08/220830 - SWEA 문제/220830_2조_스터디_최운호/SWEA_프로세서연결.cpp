#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct core {
	int y;
	int x;
};

vector<core> v;

int n;
int map[12][12];
int coreCnt;
int minVal = 21e8;

bool check(int dir, int y, int x) {
	if (dir == 0) {
		for (int i = 0; i < x; i++) {
			if (map[y][i] != 0) return false;
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < y; i++) {
			if (map[i][x] != 0) return false;
		}
	}
	else if (dir == 2) {
		for (int i = x + 1; i < n; i++) {
			if (map[y][i] != 0) return false;
		}
	}
	else {
		for (int i = y + 1; i < n; i++) {
			if (map[i][x] != 0) return false;
		}
	}

	return true;
}

int setLine(int dir, int y, int x) {
	int val = 0;

	if (dir == 0) {
		for (int i = 0; i < x; i++) {
			map[y][i] = 2;
			val++;
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < y; i++) {
			map[i][x] = 2;
			val++;
		}
	}
	else if (dir == 2) {
		for (int i = x + 1; i < n; i++) {
			map[y][i] = 2;
			val++;
		}
	}
	else {
		for (int i = y + 1; i < n; i++) {
			map[i][x] = 2;
			val++;
		}
	}

	return val;
}

void returnLine(int dir, int y, int x) {

	if (dir == 0) {
		for (int i = 0; i < x; i++) map[y][i] = 0;
	}
	else if (dir == 1) {
		for (int i = 0; i < y; i++) map[i][x] = 0;
	}
	else if (dir == 2) {
		for (int i = x + 1; i < n; i++) map[y][i] = 0;
	}
	else {
		for (int i = y + 1; i < n; i++) map[i][x] = 0;
	}
	
	return;
}

void dfs(int line, int idx) {
	if (idx == coreCnt) {
		minVal = min(minVal, line);
		return;
	}

	core now = v[idx];

	for (int dir = 0; dir < 4; dir++) {
		if (check(dir, now.y, now.x)) {
			int val = setLine(dir, now.y, now.x);
			dfs(line + val, idx + 1);
			returnLine(dir, now.y, now.x);
		}
	}
}

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> n;

		coreCnt = 0;
		minVal = 21e8;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 0) continue;
				if (i == 0 || j == 0 || i == n - 1 || j == n - 1) continue;
				v.push_back({ i,j });
				coreCnt++;
			}
		}

		dfs(0, 0);

		cout << "#" << t << " " << minVal << '\n';
		while (v.size() > 0) v.pop_back();
	}

	return 0;
}