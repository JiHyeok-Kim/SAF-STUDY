#include <iostream>
#include <cstring>
using namespace std;
int film[15][25];
int tempFilm[15][15][25];
int D, W, K, result;
int used[15];
void input() {
	result = 21e8;
	memset(film, 0, sizeof(film));
	memset(tempFilm, 0, sizeof(tempFilm));
	cin >> D >> W >> K;
	for (int y = 0; y < D; y++) {
		used[y] = 0;
		for (int x = 0; x < W; x++) {
			cin >> film[y][x];
		}
	}
}
int isPass(int lev) {
	int flag = 0;
	for (int x = 0; x < W; x++) {
		int cnt = 0, xVal = tempFilm[lev][0][x];
		for (int y = 0; y < D; y++) {
			if (xVal == tempFilm[lev][y][x]) {
				cnt++;
				if (cnt >= K) {
					flag++;
					break;
				}
			}
			else {
				xVal = tempFilm[lev][y][x];
				cnt = 1;
			}
		}
		if (flag != x + 1) return 0;
	}
	return 1;
}
void dfs(int lev, int start) {
	if (lev == K) {
		if (isPass(lev)) result = K;
		return;
	}
	if (isPass(lev)) {
		result = min(lev, result);
		return;
	}
	if (result <= lev) return;

	for (int i = start; i < D; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		memcpy(tempFilm[lev + 1], tempFilm[lev], sizeof(tempFilm[lev]));
		for (int x = 0; x < W; x++) {
			tempFilm[lev + 1][i][x] = 1;
		}
		dfs(lev + 1, i + 1);
		if (result <= lev) return;
		for (int x = 0; x < W; x++) {
			tempFilm[lev + 1][i][x] = 0;
		}
		dfs(lev + 1, i + 1);
		used[i] = 0;
		if (result <= lev) return;
	}
}
void solution() {
	memcpy(tempFilm[0], film, sizeof(film));
	dfs(0, 0);
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
	freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}
