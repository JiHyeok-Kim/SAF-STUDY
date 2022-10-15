#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
struct Node { int y, x; int sec; int lev; };
vector<Node> p;
vector<Node> s;
vector<Node> ap[2];
int N, map[11][11], result;
int sp[2][3];
void input() {
	p.clear();
	s.clear();
	ap[0].clear();
	ap[1].clear();
	result = 21e8;
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) p.push_back({ y,x });
			if (map[y][x] > 1) s.push_back({ y,x,map[y][x] });
		}
}
bool cmp(Node t, Node v) {
	return t.sec < v.sec;
}
bool cmp1(Node t, Node v) {
	return t.lev < v.lev;
}
int getDist(int lev, int i) {
	int dist = abs(s[i].y - p[lev].y) + abs(s[i].x - p[lev].x);
	return dist;
}
void setResult() {
	memset(sp, 0, sizeof(sp));
	int tempResult = -1;
	for (int j = 0; j < 2; j++) {
		sort(ap[j].begin(), ap[j].end(), cmp);
		for (int i = 0; i < ap[j].size(); i++) {
			int mini = 21e8, minidx = 0;
			for (int k = 0; k < 3; k++) {
				if (sp[j][k] < mini) {
					mini = sp[j][k];
					minidx = k;
				}
			}
			if (sp[j][minidx] > ap[j][i].sec) sp[j][minidx] += s[j].sec;
			else sp[j][minidx] = ap[j][i].sec + s[j].sec;
		}
		int maxi = -1, maxidx = 0;
		for (int k = 0; k < 3; k++) {
			if (sp[j][k] > maxi) {
				maxi = sp[j][k];
				maxidx = k;
			}
		}
		tempResult = max(tempResult, sp[j][maxidx]);
	}
	result = min(result, tempResult);
}

void dfs(int lev) {
	if (lev == p.size()) {
		setResult();
		for (int j = 0; j < 2; j++) {
			sort(ap[j].begin(), ap[j].end(), cmp1);
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		ap[i].push_back({ p[lev].y,p[lev].x,getDist(lev,i),lev });
		dfs(lev + 1);
		ap[i].pop_back();
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		dfs(0);
		cout << "#" << t << " " << result+1 << "\n";
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