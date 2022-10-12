#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct pos {
	int y;
	int x;
};

int map[101][101];
pos warmHole[101][101];
int n;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

vector<pos> canStart;
vector<pos> wH[11];

int maxScore = 0;

void init() {
	cin >> n;
	maxScore = 0;

	memset(map, 0, sizeof(map));

	canStart.clear();
	for (int i = 6; i <= 10; i++) {
		wH[i].clear();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) canStart.push_back({ i,j });
			if (map[i][j] >= 6 && map[i][j] <= 10) wH[map[i][j]].push_back({ i,j });
		}
	}

	for (int i = 6; i <= 10; i++) {
		if (wH[i].size() > 0) {
			warmHole[wH[i][0].y][wH[i][0].x].y = wH[i][1].y;
			warmHole[wH[i][0].y][wH[i][0].x].x = wH[i][1].x;
			warmHole[wH[i][1].y][wH[i][1].x].y = wH[i][0].y;
			warmHole[wH[i][1].y][wH[i][1].x].x = wH[i][0].x;
		}
	}

	return;
}
int changeDir(int type, int d) {
	if (type == 1) {
		if (d == 0) return 1;
		else if (d == 1) return 3;
		else if (d == 2) return 0;
		else if (d == 3) return 2;
	}
	else if (type == 2) {
		if (d == 0) return 3;
		else if (d == 1) return 0;
		else if (d == 2) return 1;
		else if (d == 3) return 2;
	}
	else if (type == 3) {
		if (d == 0) return 2;
		else if (d == 1) return 0;
		else if (d == 2) return 3;
		else if (d == 3) return 1;
	}
	else if (type == 4) {
		if (d == 0) return 1;
		else if (d == 1) return 2;
		else if (d == 2) return 3;
		else if (d == 3) return 0;
	}
	else if (type == 5) {
		if (d == 0) return 1;
		else if (d == 1) return 0;
		else if (d == 2) return 3;
		else if (d == 3) return 2;
	}
}
int crushWall(int dir) {
	if (dir == 0) return 1;
	else if (dir == 1) return 0;
	else if (dir == 2) return 3;
	else if (dir == 3) return 2;
}
int go(int y, int x, int dir) {
	int score = 0;

	int startY = y;
	int startX = x;

	while (1) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (map[ny][nx] == -1 || (ny == startY && nx == startX)) return score;

		if ((map[ny][nx] >= 1 && map[ny][nx] <= 5)) {
			dir = changeDir(map[ny][nx], dir);
			score++;
		}

		if (ny < 1 || nx < 1 || ny > n || nx > n) {
			dir = crushWall(dir);
			score++;
		}


		if (map[ny][nx] >= 6 && map[ny][nx] <= 10) {
			y = warmHole[ny][nx].y;
			x = warmHole[ny][nx].x;
			continue;
		}
		
		y = ny;
		x = nx;
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();

		for (auto loop : canStart) {
			for (int i = 0; i < 4; i++) {
				int getScore = go(loop.y, loop.x, i);
				maxScore = max(maxScore, getScore);
			}
		}

		cout << "#" << t << " " << maxScore << '\n';

		canStart.clear();
		for (int i = 6; i <= 10; i++) {
			if (wH[i].size() == 0) continue;
			warmHole[wH[i][0].y][wH[i][0].x].y = 0;
			warmHole[wH[i][0].y][wH[i][0].x].x = 0;
			warmHole[wH[i][1].y][wH[i][1].x].y = 0;
			warmHole[wH[i][1].y][wH[i][1].x].x = 0;
			wH[i].clear();
		}

	}

	return 0;
}