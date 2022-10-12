#include <iostream>
#include <queue>
using namespace std;

int N, K, top, maxi;
int map[8][8];
int visit[8][8];
int directY[4] = { -1,1,0,0 }; //»óÇÏÁÂ¿ì
int directX[4] = { 0,0,-1,1 };

void init()
{
	top = maxi = 0;
	cin >> N >> K;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] > top) top = map[y][x];
		}
	}

	return;
}

void dfs(int lev, int ty, int tx, int h, int flag)
{
	if (lev > maxi) maxi = lev;

	for (int i = 0; i < 4; i++)
	{
		int ny = ty + directY[i];
		int nx = tx + directX[i];
		if (visit[ny][nx] == 1) {
			if (lev > maxi) maxi = lev;
			continue;
		}
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

		int nh = map[ny][nx];
		if (nh >= h && flag > 0) continue;
		if (nh >= h && flag == 0) {
			if (nh - K < h) {
				visit[ny][nx] = 1;
				dfs(lev + 1, ny, nx, h - 1, flag + 1);
				visit[ny][nx] = 0;
			}
			continue;
		}

		visit[ny][nx] = 1;

		dfs(lev + 1, ny, nx, nh, flag);

		visit[ny][nx] = 0;
	}

}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] != top) continue;

				visit[y][x] = 1;
				dfs(1, y, x, map[y][x], 0);
				visit[y][x] = 0;
			}
		}

		cout << "#" << tc << " " << maxi << "\n";
	}

	return 0;
}