#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct pos {
	int y;
	int x;
	int t;
};

int map[50][50];
bool canGo[50][50];

int go[8] = { 0,4,2,2,2,2,2,2 };

int dy[8][4] = {
	{0},
	{-1,1,0,0},
	{-1,1},
	{0,0},
	{-1,0},
	{1,0},
	{1,0},
	{-1,0}
};
int dx[8][4] = {
	{0},
	{0,0,-1,1},
	{0,0},
	{-1,1},
	{0,1},
	{0,1},
	{0,-1},
	{0,-1}
};

bool check(int type1, int type2, int dir) {
	if (type2 == 1) return true;

	if (type1 == 1) {
		if (dir == 0 && (type2 == 2 || type2 == 5 || type2 == 6)) return true;
		else if (dir == 1 && (type2 == 2 || type2 == 4 || type2 == 7)) return true;
		else if (dir == 2 && (type2 == 3 || type2 == 4 || type2 == 5)) return true;
		else if (dir == 3 && (type2 == 3 || type2 == 6 || type2 == 7)) return true;
	}
	else if (type1 == 2) {
		if (dir == 0 && (type2 == 2 || type2 == 5 || type2 == 6)) return true;
		else if (dir == 1 && (type2 == 2 || type2 == 4 || type2 == 7)) return true;
	}
	else if (type1 == 3) {
		if (dir == 0 && (type2 == 3 || type2 == 4 || type2 == 5)) return true;
		else if (dir == 1 && (type2 == 3 || type2 == 6 || type2 == 7)) return true;
	}
	else if (type1 == 4) {
		if (dir == 0 && (type2 == 2 || type2 == 5 || type2 == 6)) return true;
		else if (dir == 1 && (type2 == 3 || type2 == 6 || type2 == 7)) return true;
	}
	else if (type1 == 5) {
		if (dir == 0 && (type2 == 2 || type2 == 4 || type2 == 7)) return true;
		else if (dir == 1 && (type2 == 3 || type2 == 6 || type2 == 7)) return true;
	}
	else if (type1 == 6) {
		if (dir == 0 && (type2 == 2 || type2 == 4 || type2 == 7)) return true;
		else if (dir == 1 && (type2 == 3 || type2 == 4 || type2 == 5)) return true;
	}
	else if (type1 == 7) {
		if (dir == 0 && (type2 == 2 || type2 == 5 || type2 == 6)) return true;
		else if (dir == 1 && (type2 == 3 || type2 == 4 || type2 == 5)) return true;
	}

	return false;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n, m, r, c, k;
		cin >> n >> m >> r >> c >> k;

		int result = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				canGo[i][j] = false;
			}
		}


		queue<pos> q;
		q.push({ r,c,1 });
		canGo[r][c] = true;

		while (!q.empty()) {
			pos now = q.front();
			q.pop();

			result++;

			if (now.t == k) {
				continue;
			}

			for (int i = 0; i < go[map[now.y][now.x]]; i++) {
				int ny = now.y + dy[map[now.y][now.x]][i];
				int nx = now.x + dx[map[now.y][now.x]][i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if (map[ny][nx] == 0) continue;
				if (!check(map[now.y][now.x], map[ny][nx], i)) continue;
				if (canGo[ny][nx]) continue;
				canGo[ny][nx] = true;
				q.push({ ny, nx, now.t + 1 });
			}
			
		}

		cout << "#" << t << " " << result << '\n';
	}
}