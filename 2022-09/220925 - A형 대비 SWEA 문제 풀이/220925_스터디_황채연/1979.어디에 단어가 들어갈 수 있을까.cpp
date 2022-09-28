#include <iostream>
using namespace std;

int T, N, K;
int MAP[15][15];
bool visited[15][15];
int ret;

const int dy[] = { 0,1 };
const int dx[] = { 1,0 };


void DFS(int cnt, int sy, int sx, int ny, int nx, int dir) {
	if (cnt == K) {
		int by = sy - dy[dir];
		int bx = sx - dx[dir];
		int nny = ny + dy[dir];
		int nnx = nx + dx[dir];
		if ((by < 0 || by >= N || bx < 0 || bx >= N || MAP[by][bx] == 0)
			&& (nny < 0 || nny >= N || nnx < 0 || nnx >= N || MAP[nny][nnx] == 0)) ret++;
		return;
	}

	int nny = ny + dy[dir];
	int nnx = nx + dx[dir];
	if (nny < 0 || nny >= N || nnx < 0 || nnx >= N) return;
	if (MAP[nny][nnx] == 1) {
		DFS(cnt + 1, sy, sx, nny, nnx, dir);
	}
}

int Solve() {
	ret = 0;
	// todo something...
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (MAP[y][x] == 1) {
				for (int dir = 0; dir < 2; ++dir) {
					DFS(1, y, x, y, x, dir);
				}
			}
		}
	}

	return ret;
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				cin >> MAP[y][x];
			}
		}
		int res = Solve();
		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}