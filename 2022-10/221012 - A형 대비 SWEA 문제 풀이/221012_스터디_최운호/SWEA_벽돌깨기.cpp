#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct info {
	int y;
	int x;
	int val;
};



int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, W, H;
int map[15][12];

int cur[15][12];
int one[15][12];
int two[15][12];
int three[15][12];

int used[15][12];
int getMin = 21e8;



void getBomb(int x) {
	int tar = -1;
	for (int i = 0; i < H; i++) {
		if (cur[i][x] > 0) {
			tar = i;
			break;
		}
	}
	if (tar == -1) return;

	queue<info> q;
	q.push({ tar, x, cur[tar][x] });
	used[tar][x] = 1;


	while (!q.empty()) {
		info now = q.front();
		q.pop();

		cur[now.y][now.x] = 0;
		if (now.val == 1) continue;

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < now.val; j++) {
				int ny = now.y + (dy[i] * j);
				int nx = now.x + (dx[i] * j);
				if (ny < 0 || nx < 0 || nx >= W || ny >= H) continue;
				if (cur[ny][nx] == 0) continue;
				if (used[ny][nx] == 1) continue;
				used[ny][nx] = 1;
				q.push({ ny, nx, cur[ny][nx] });
			}
		}
	}
}

void init_used() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			used[i][j] = 0;
		}
	}
}

void drop() {
	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 0; j--) {
			if (cur[j][i] == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (cur[k][i] != 0) {
						cur[j][i] = cur[k][i];
						cur[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

void copyMap() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cur[i][j] = map[i][j];
		}
	}
}

void saveMap(int lev) {
	if (lev == 0) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				one[i][j] = cur[i][j];
			}
		}
	}
	else if (lev == 1) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				two[i][j] = cur[i][j];
			}
		}
	}
	else if (lev == 2) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				three[i][j] = cur[i][j];
			}
		}
	}
	else return;
}

void returnMap(int lev) {
	if (lev == 1) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cur[i][j] = one[i][j];
			}
		}
	}
	else if (lev == 2) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cur[i][j] = two[i][j];
			}
		}
	}
	else if (lev == 3) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cur[i][j] = three[i][j];
			}
		}
	}
}

int cntBrick() {
	int cnt = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (cur[i][j] > 0) cnt++;
		}
	}

	return cnt;
}

void bfs(int now, int lev) {
	if (lev == N) {
		int remain = cntBrick();
		if (remain < getMin) getMin = remain;
		return;
	}

	init_used();

	getBomb(now);

	drop();

	saveMap(lev);

	for (int i = 0; i < W; i++) {
		bfs(i, lev + 1);
		returnMap(lev + 1);
	}
}

void init() {
	getMin = 21e8;
	init_used();
	cin >> N >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
}

int main() {
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		init();
		int a = 8;
		for (int i = 0; i < W; i++) {
			copyMap();
			bfs(i, 0);
		}

		cout << "#" << t << " " << getMin << '\n';
	}

	return 0;
}