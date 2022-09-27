#include <iostream>
#include <string.h>
using namespace std;

int snail[10][10];
int n;
int maxLev;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(int y, int x, int dir, int lev, int val) {
	if (lev == maxLev) {
		return;
	}
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if ((ny < 0 || nx < 0 || ny >= n || nx >= n) || snail[ny][nx] != 0) {
		int nextDir = (dir + 1) % 4;
		dfs(y, x, nextDir, lev, val);
	}
	else {
		snail[ny][nx] = val + 1;
		dfs(ny, nx, dir, lev + 1, val + 1);
	}
}


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> n;
		maxLev = n * n;

		snail[0][0] = 1;
		
		dfs(0,0,0,1,1);

		cout << "#" << t << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << snail[i][j] << " ";
			}
			cout << '\n';
		}
		memset(snail, 0, sizeof(snail));
	}

	return 0;
}