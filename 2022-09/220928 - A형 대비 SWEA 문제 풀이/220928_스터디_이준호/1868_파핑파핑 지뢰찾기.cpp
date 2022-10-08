#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n, ans;
vector<string> map;
int ditY[8] = { -1,-1,-1,0,0,1,1,1 };
int ditX[8] = { -1,0,1,-1,1,-1,0,1 };
int sum;

struct Node {
	int y, x;
};
queue<Node> q;

void init() {
	ans = 0;
	sum = 0;
	map.clear();
}

void input() {
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		map.push_back(temp);
	}
}

bool isClear(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int ny = y + ditY[i];
		int nx = x + ditX[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (map[ny][nx] == '*') return 0;
	}
	return 1;
}

void fp(int a, int b) {
	q.push({ a,b });
	map[a][b] = '1';
	sum++;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (isClear(now.y, now.x) == 0) {
			map[now.y][now.x] = '1';
			continue;
		}

		for (int i = 0; i < 8; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (map[ny][nx] == '1') continue;
			map[ny][nx] = '1';
			q.push({ ny,nx });
		}
	}

}



void solve() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == '.') {
				if (isClear(y,x)) {
					fp(y, x);
				}
			}
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == '.') sum++;
		}
	}
	ans = sum;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> n;
		init();
		input();

		solve();

		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}