#include <iostream>
#include <vector>
using namespace std;
int N, M, C, result, max1, max2;
int map[11][11];
int tong[2][6];

void input() {
	cin >> N >> M >> C;
	for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) cin >> map[y][x];
	result = 0;
}
void dfs(int lev, int sum, int s_sum, int tar) {
	if (sum > C) return;
	if (lev == M) {
		if (tar == 0) max1 = max(max1, s_sum);
		if (tar == 1) max2 = max(max2, s_sum);
		return;
	}

	for (int i = 0; i < 2; i++) {
		dfs(lev + 1, sum + tong[tar][lev] * i, s_sum + tong[tar][lev] * tong[tar][lev] * i, tar);
	}
}
void setMax() {
	max1 = 0; max2 = 0;
	dfs(0, 0, 0, 0);
	dfs(0, 0, 0, 1);
	result = max(result, max1 + max2);
	int a = 0;
}
void solution() {
	for (int y1 = 0; y1 < N; y1++) {
		for (int x1 = 0; x1 < N-M+1; x1++) {
			for (int i = 0; i < M; i++) tong[0][i] = map[y1][x1 + i];
			int sy = y1, sx = x1 + M;
			if (sx + M > N+1) {
				sy = y1 + 1;
				sx = 0;
			}
			for (int y2 = sy; y2 < N; y2++) {
				for (int x2 = sx; x2 < N-M+1; x2++) {
					for (int i = 0; i < M; i++) tong[1][i] = map[y2][x2 + i];
					setMax();
				}
				sx = 0;
			}
		}
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		solution();
		cout << "#" << t << " " << result << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}