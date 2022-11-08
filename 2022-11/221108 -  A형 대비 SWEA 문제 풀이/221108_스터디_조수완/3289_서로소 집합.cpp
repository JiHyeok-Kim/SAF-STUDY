#include <iostream>
using namespace std;
int T, m, n;
int c, a, b;
int parents[1000100];
int findP(int tar) {
	if (parents[tar] == tar)return tar;
	return parents[tar] = findP(parents[tar]);
}
void uni(int a, int b) {
	int pa = findP(a);
	int pb = findP(b);
	if (pa == pb) return;
	parents[pb] = pa;
}
void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)parents[i] = i;
		cout << "#" << t << " ";
		for (int i = 0; i < m; i++) {
			cin >> c >> a >> b;
			if (c == 0)uni(a, b);
			if (c == 1) {
				if (findP(a) == findP(b)) cout << "1";
				else cout << "0";
			}
		}
		cout << "\n";
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