#include <iostream>
#include <queue>
using namespace std;

int N, K;
int map[8][8];
int maxTall;
int path[20];
int dig;
int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };
int ans;

struct Node {
	int y, x;
};
queue<Node> q;
Node now;

void init() {
	ans = -21e8;
	maxTall = -21e8;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			map[y][x] = 0;
		}
	}
}

void input() {
	cin >> N >> K;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (maxTall < map[y][x]) {
				maxTall = map[y][x];
			}
		}
	}
}

void findMaxTall() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == maxTall) {
				q.push({ y,x });
			}
		}
	}
}

bool canGo(int tar, int yy, int xx) {
	for (int i = 0; i < 4; i++) {
		int ny = yy + ditY[i];
		int nx = xx + ditX[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (path[tar - 1] <= map[ny][nx]) continue;
		return 1;
	}
	return 0;
}

void dfs(int lev, int yy, int xx) {
	if (!canGo(lev, yy, xx)) {
		if (ans < lev) {
			ans = lev;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = yy + ditY[i];
		int nx = xx + ditX[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (map[yy][xx] <= map[ny][nx]) continue;

		path[lev] = map[ny][nx];
		dfs(lev + 1, ny, nx);
		path[lev] = 0;
	}

}

void solve() {
	
	findMaxTall();
	
	while (!q.empty()) {
		now = q.front();
		q.pop();

		dig = 0;
		path[0] = map[now.y][now.x];
		// 제일 높은거 기준 잡고 전체 다 K까지 파보기
		while (1) {
			if (dig == K + 1) break;
			if (dig == 0) dfs(1, now.y, now.x);
			else 
			{	
				for (int y = 0; y < N; y++) {
					for (int x = 0; x < N; x++) {
						if (y == now.y && x == now.x) continue;
						if (map[y][x] - dig < 0) continue;

						map[y][x] -= dig;
						dfs(1, now.y, now.x);
						map[y][x] += dig;
					}
				}
			}
			dig++;
		}
		
	}

}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
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