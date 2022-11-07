#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#include <queue>
using namespace std;
int N, idx, result;
int amat[220][200];
unordered_map<string, int> used;

void input() {
	result = 1;
	used = unordered_map<string, int>();
	memset(amat, 0, sizeof(amat));
	idx = 0;
	cin >> N;
	string n1, n2;
	for (int i = 0; i < N; i++) {
		cin >> n1 >> n2;
		if (used.count(n1) == 0) { used[n1] = idx++; }
		if (used.count(n2) == 0) { used[n2] = idx++; }
		amat[used[n1]][used[n2]] = 1;
		amat[used[n2]][used[n1]] = 1;
	}
}
void bfs() {
	int info[220] = { 0 };
	queue<pair<int,int>> q;
	info[0] = 1;
	q.push({ 0,0 });

	while (!q.empty()) {
		pair<int,int> now = q.front();
		q.pop();

		for (int i = 0; i < idx; i++) {
			if (amat[now.first][i] == 0)continue;
			if (info[i] == info[now.first]) { result = 0; return; }
			if (info[i] != 0) continue;
			info[i] = ((now.second+1) % 2) + 1;
			q.push({ i, now.second + 1 });
		}
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		bfs();
		if (result == 1) cout << "#" << t << " Yes\n";
		else cout << "#" << t << " No\n";
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