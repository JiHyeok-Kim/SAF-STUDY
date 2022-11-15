#include <iostream>
#include <vector>
using namespace std;
int T, N, r;
vector<pair<int, int>> c;

void dfs(int y, int x, int d, int l,int* u) {
	if (d > r) return;
	if (l == N) {
		int dist = d + (c[1].first < y ? y - c[1].first : c[1].first - y) + (c[1].second < x ? x - c[1].second : c[1].second - x);
		if (dist < r) r = dist;
		return;
	}
	for (int i = 2; i < N + 2; i++) {
		if (u[i] == 1)continue;
		int tmp = (c[i].first < y ? y - c[i].first : c[i].first - y) + (c[i].second < x ? x - c[i].second : c[i].second - x);
		u[i] = 1;
		dfs(c[i].first, c[i].second, d + tmp, l + 1, u);
		u[i] = 0;
	}
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		c.clear();
		r = 21e8; int u[15] = { 0 };
		cin >> N;
		for (int i = 0; i < N + 2; i++) {
			int x, y;
			cin >> y >> x;
			c.push_back({ y,x });
		}
		dfs(c[0].first, c[0].second, 0, 0, u);
		cout << "#" << t << " " << r << "\n";
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