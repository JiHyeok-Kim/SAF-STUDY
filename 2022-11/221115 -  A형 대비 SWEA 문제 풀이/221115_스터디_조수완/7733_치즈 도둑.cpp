#include <iostream>
#include <queue>
using namespace std;
int T, N, r, mx;
int m[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void input() {
	mx = 0, r = 1;
	cin >> N;
	for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) {
		cin >> m[y][x]; if (mx < m[y][x])mx = m[y][x];
	}
}
int simulation(int tar) {
	int u[101][101] = { 0 }, c = 0;
	for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) {
		if (m[y][x] <= tar)continue;
		if (u[y][x] == 1)continue;
		queue<pair<int, int>> q;
		q.push({ y,x });
		u[y][x] = 1;
		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = now.first + dy[i];
				int nx = now.second + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
				if (u[ny][nx] == 1)continue;
				if (m[ny][nx] <= tar)continue;
				u[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
		c++;
	}
	return c;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		input();
		for (int i = 1; i < mx; i++) {
			int c = simulation(i);
			if (r < c) r = c;
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