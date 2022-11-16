#include <iostream>
#include <unordered_map>
using namespace std;
int T, r;
char m[5][5];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
unordered_map<string, int> um;

void dfs(int l,string s,int y,int x) {
	if (l == 7) {
		if (um.count(s) == 0) { 
			r++; um[s] = 1; 
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)continue;
		dfs(l + 1, s + m[ny][nx], ny, nx);
	}
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		r = 0;
		um = unordered_map<string, int>();
		for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)cin >> m[y][x];
		for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)dfs(0, "", y, x);
		cout << "#" << t << " " << r << "\n";
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