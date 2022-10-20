#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char map[20][20];
int R, C;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

unordered_map<string, bool> um;

int flag;
int ret;

void init() {
	cin >> R >> C;
	flag = 0;
	ret = 0;
	um.clear();

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			map[i][j] = str[j];
			if (map[i][j] == '@') ret = 1;
		}
	}
}

string makeKey(int y, int x, int dir, int memo)
{
	string temp = "";

	temp += to_string(y);
	temp += '/';
	temp += to_string(x);
	temp += '/';
	temp += to_string(dir);
	temp += '/';
	temp += to_string(memo);

	return temp;
}

int changeDir(char ch) {
	if (ch == 'v') return 3;
	if (ch == '<') return 0;
	if (ch == '>') return 1;
	if (ch == '^') return 2;
}

void dfs(int y, int x, int dir, int memo) {
	if (flag == 1) return;

	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0) ny = R - 1;
	if (nx < 0) nx = C - 1;
	if (ny >= R) ny = 0;
	if (nx >= C) nx = 0;

	char next = map[ny][nx];

	if (next == '^' || next == 'v' || next == '<' || next == '>') {
		int nDir = changeDir(next);
		string key = makeKey(ny, nx, nDir, memo);
		if (um.count(key) != 0) return;
		um[key] = true;
		dfs(ny, nx, nDir, memo);
		um.erase(key);
	}
	else if (next >= '0' && next <= '9') {
		int setMemo = next - '0';
		string key = makeKey(ny, nx, dir, setMemo);
		if (um.count(key) != 0) return;
		um[key] = true;
		dfs(ny, nx, dir, setMemo);
		um.erase(key);
	}
	else if (next == '.') {
		string key = makeKey(ny, nx, dir, memo);
		if (um.count(key) != 0) return;
		um[key] = true;
		dfs(ny, nx, dir, memo);
		um.erase(key);
	}
	else if (next == '+') {
		int nextMemo = memo + 1;
		if (nextMemo > 15) nextMemo = 0;
		string key = makeKey(ny, nx, dir, nextMemo);
		if (um.count(key) != 0) return;
		um[key] = true;
		dfs(ny, nx, dir, nextMemo);
		um.erase(key);
	}
	else if (next == '-') {
		int nextMemo = memo - 1;
		if (nextMemo < 0) nextMemo = 15;
		string key = makeKey(ny, nx, dir, nextMemo);
		if (um.count(key) != 0) return;
		um[key] = true;
		dfs(ny, nx, dir, nextMemo);
		um.erase(key);
	}
	else if (next == '|') {
		int nDir;
		if (memo == 0) nDir = 3;
		else nDir = 2;
		string key = makeKey(ny, nx, nDir, memo);
		if (um.count(key) != 0) return;
		um[key] = true;
		dfs(ny, nx, nDir, memo);
		um.erase(key);
	}
	else if (next == '_') {
		int nDir;
		if (memo == 0) nDir = 1;
		else nDir = 0;
		string key = makeKey(ny, nx, nDir, memo);
		if (um.count(key) != 0) return;
		um[key] = true;
		dfs(ny, nx, nDir, memo);
		um.erase(key);
	}
	else if (next == '?') {
		for (int i = 0; i < 4; i++) {
			string key = makeKey(ny, nx, i, memo);
			if (um.count(key) != 0) continue;
			um[key] = true;
			dfs(ny, nx, i, memo);
		}
	}
	else if (next == '@') {
		flag = 1;
		return;
	}
}

void solve() {
	int stMemo = 0;
	int dir = 1;
	char st = map[0][0];

	if (map[0][0] >= '0' && map[0][0] <= '9') {
		stMemo = map[0][0] - '0';
	}
	else if (st == '^' || st == 'v' || st == '>' || st == '<') {
		dir = changeDir(st);
	}
	string key = makeKey(0, 0, dir, stMemo);
	um[key] = 1;
	dfs(0, 0, dir, stMemo);
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();

		if(ret == 1) solve();

		if (flag) cout << "#" << t << " " << "YES" << '\n';
		else cout << "#" << t << " " << "NO" << '\n';
	}
	return 0;
}