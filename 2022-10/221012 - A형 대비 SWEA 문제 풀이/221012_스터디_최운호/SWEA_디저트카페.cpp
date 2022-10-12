#include <iostream>
#include <queue>
using namespace std;

int n;
int map[20][20];

int used[20][20];

int dat[101];

int desY, desX;

int getMax = -1;

int dy[4] = { -1,-1,1,1 };
int dx[4] = { -1,1,-1,1 };

void init() {
	getMax = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void dfs(int y, int x, int move, int turn, int prevT) {
	if (turn > 4) return;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		int isTurn = 0;
		if (prevT != i) isTurn = 1;
		if (ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
		if (ny == desY && nx == desX) {
			if (turn + isTurn == 4) {
				if (move + 1 > getMax) getMax = move + 1;
				return;
			}
		}
		if (used[ny][nx] == 1) continue;
		if (dat[map[ny][nx]] != 0) continue;
		used[ny][nx] = 1;
		dat[map[ny][nx]] = 1;
		dfs(ny, nx, move + 1, turn + isTurn, i);
		used[ny][nx] = 0;
		dat[map[ny][nx]] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase = 0;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		init();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i == 0 && (j == 0 || j == n - 1)) || (i == n - 1 && (j == 0 || j == n - 1))) continue;
				desY = i;
				desX = j;
				used[i][j] = 1;
				dat[map[i][j]] = 1;
				dfs(i, j, 0, 0, -1);
				dat[map[i][j]] = 0;
				used[i][j] = 0;
			}
		}
		cout << "#" << t << " " << getMax << '\n';
	}
}