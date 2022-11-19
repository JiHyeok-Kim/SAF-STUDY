#include <iostream>
using namespace std;
char map[9][9], ans[4];
int result, cnt, used[9];
void input() {
	result = -1;
	cnt = 0;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'O') cnt++;
		}
		if (cnt != y + 1) cnt = 0;
		used[y] = 0;
	}
}
void dfs(int lev) {
	if (lev == 8) {
		result = 1;
		return;
	}
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		if (map[lev][i] == '.')continue;
		if (used[i] == 1) break;
		used[i] = 1;
		dfs(lev + 1);
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		if (cnt == 8) dfs(0);
		if (result == -1) cout << "#" << t << " no\n";
		else cout << "#" << t << " yes\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}