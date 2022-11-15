#include <iostream>
using namespace std;
int T, N;
char m[1010][1010];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		int g[1010] = { 0 }, s[1010] = { 0 }, r = 0;
		cin >> N;
		for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) {
			cin >> m[y][x]; if (m[y][x] == 'B') { g[y]++; s[x]++; }
		}
		for (int y = 0; y < N; y++){
			for (int x = 0; x < N; x++) {
				if ((m[y][x] == 'B' ? g[y] + s[x] - 1 : g[y] + s[x]) % 2 == 1)r++;
			}
		}
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