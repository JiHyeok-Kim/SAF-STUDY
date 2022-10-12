#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pos {
	int y;
	int x;
};

int N;
int map[8][8];
int used[8][8];
int K;
int answer;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x, int lev, int flag) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		int ret = -1;
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (used[ny][nx] == 1) continue;
		if (map[y][x] <= map[ny][nx] && flag == 1) continue;
		if (map[ny][nx] - K >= map[y][x]) continue;
		if (map[y][x] <= map[ny][nx]) {
			ret = map[ny][nx];
			map[ny][nx] = map[y][x] - 1;
		}
		used[ny][nx] = 1;
		if (ret == -1) dfs(ny, nx, lev + 1, flag);
		else {
			dfs(ny, nx, lev + 1, 1);
			map[ny][nx] = ret;
		}
		used[ny][nx] = 0;
	}

	answer = max(answer, lev);
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> K;
		int maxi = 0;
		answer = 0;
		vector<pos> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				maxi = max(maxi, map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == maxi) v.push_back({ i,j });
			}
		}

		for (auto loop : v) {
			used[loop.y][loop.x] = 1;
			dfs(loop.y, loop.x, 1, 0);
			used[loop.y][loop.x] = 0;
		}

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}