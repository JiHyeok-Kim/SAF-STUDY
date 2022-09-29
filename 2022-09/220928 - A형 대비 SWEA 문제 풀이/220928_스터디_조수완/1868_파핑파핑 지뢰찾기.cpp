#include <iostream>
#include <queue>
using namespace std;
struct Node { int y, x; };
int N, used[350][350], cnt, cnt1;
char map[350][350];
int drY[8] = { -1,1,0,0,-1,-1,1,1 };
int drX[8] = { 0,0,-1,1,-1,1,-1,1 };
queue<Node> q;

bool isBoom(int sy,int sx) {
	for (int i = 0; i < 8; i++) {
		int ny = sy + drY[i];
		int nx = sx + drX[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (map[ny][nx] == '*') return true;
	}
	return false;
}
void input() {
	cnt = 0;
	cnt1 = 0;
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			used[y][x] = 0;
			cin >> map[y][x];
			if (map[y][x] == '.') cnt++;
		}
	}
}
void setMap(int sy,int sx) {
	used[sy][sx] = 1;
	q.push({ sy,sx });
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (isBoom(now.y, now.x)) continue;
		for (int i = 0; i < 8; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (used[ny][nx] == 1)continue;
			if (map[ny][nx] != '.')continue;
			cnt--;
			used[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}

void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] == '.' && !isBoom(y, x)) {
					setMap(y, x);
					cnt--;
					cnt1++;
				}
			}
		}
		cout << "#" << t << " " << cnt + cnt1 << "\n";
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