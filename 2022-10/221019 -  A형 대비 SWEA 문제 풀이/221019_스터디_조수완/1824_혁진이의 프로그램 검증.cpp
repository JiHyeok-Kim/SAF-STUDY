#include <iostream>
#include <cstring>
using namespace std;
struct Node { int y, x, dir; };
char cmd[22][22];
int used[22][22][20][5];
int mem, R, C, T, result, flag1;
int drY[4] = { 0,1,0,-1 };
int drX[4] = { 1,0,-1,0 };

void input() {
	result = 0, flag1 = 0;
	cin >> R >> C;
	for (int y = 0; y < R; y++)for (int x = 0; x < C; x++) {
		cin >> cmd[y][x];
		if (cmd[y][x] == '@') flag1 = 1;
	}
	memset(used, 0, sizeof(used));
}
Node findCoor(int nowy, int nowx, int mem, int dir) {
	if (cmd[nowy][nowx] == '<') dir = 2;
	else if (cmd[nowy][nowx] == '>') dir = 0;
	else if (cmd[nowy][nowx] == '^') dir = 3;
	else if (cmd[nowy][nowx] == 'v') dir = 1;
	else if (cmd[nowy][nowx] == '_') { if (mem == 0) dir = 0; else dir = 2; }
	else if (cmd[nowy][nowx] == '|') { if (mem == 0) dir = 1; else dir = 3; }
	int ny = nowy + drY[dir]; if (ny < 0) ny = R - 1;
	int nx = nowx + drX[dir]; if (nx < 0) nx = C - 1;
	if (used[ny % R][nx % C][mem][dir] == 1) return { ny % R,nx % C,-1 };
	return { ny % R,nx % C,dir };
}
void dfs(int nowy, int nowx,int mem,int dir) {
	if (cmd[nowy][nowx] == '@') {
		result = 1;
		return;
	}
	if (result == 1) return;
	if (cmd[nowy][nowx] >= '0' && cmd[nowy][nowx] <= '9') mem = cmd[nowy][nowx] - '0';
	else if (cmd[nowy][nowx] == '+') { mem++; if (mem == 16) mem = 0; }
	else if (cmd[nowy][nowx] == '-') { mem--; if (mem == -1) mem = 15; }
	if (cmd[nowy][nowx] == '?') for (int i = 0; i < 4; i++) {
		if (result == 1) return;
		Node next = findCoor(nowy, nowx, mem, (dir + i + 1) % 4);
		if (next.dir == -1) continue;
		used[next.y][next.x][mem][next.dir] = 1;
		dfs(next.y, next.x, mem, next.dir);
		if (result == 1) return;
	}
	else {
		Node next = findCoor(nowy, nowx, mem, dir);
		if (next.dir == -1) return;
		used[next.y][next.x][mem][next.dir] = 1;
		dfs(next.y, next.x, mem, next.dir);
	}
}
void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		if (flag1)dfs(0, 0, 0, 0);
		if (result == 1)cout << "#" << t << " YES\n";
		else cout << "#" << t << " NO\n";
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