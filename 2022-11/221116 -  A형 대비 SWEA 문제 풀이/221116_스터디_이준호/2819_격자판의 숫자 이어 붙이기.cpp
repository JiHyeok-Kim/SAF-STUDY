#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int ans;
string map[4];
unordered_map<string, int> um;
// µ¿¼­³²ºÏ
int ditY[] = { 0,0,-1,1 };
int ditX[] = { 1,-1,0,0 };

void input() {
	ans = 0;
	um.clear();
	string tmp;
	for (int y = 0; y < 4; y++) {
		map[y] = "";
		for (int x = 0; x < 4; x++) {
			cin >> tmp;
			map[y] += tmp;
		}
	}
}

bool isOut(int ny, int nx) {
	return ny < 0 || nx < 0 || ny >= 4 || nx >= 4;
}

void dfs(int lev, string str, int nowY, int nowX) {
	int de = 1;
	if (lev == 6) {
		if (um.count(str) == 0) {
			um[str]++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = nowY + ditY[i];
		int nx = nowX + ditX[i];
		if (isOut(ny, nx)) continue;
		dfs(lev + 1, str + map[ny][nx], ny, nx);
	}
}

void solve() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			string a = "";
			dfs(0, a + map[y][x], y, x);
		}
	}

	ans = um.size();
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}