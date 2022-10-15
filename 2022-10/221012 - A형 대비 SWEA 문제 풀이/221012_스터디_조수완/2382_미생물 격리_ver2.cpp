#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct Node { int y, x, num, dir, id; };
int T, N, M, K, result;
int drY[5] = { 0,-1,1,0,0 };
int drX[5] = { 0,0,0,-1,1 };
vector<Node> p;
vector<int> map[110][110];
bool cmp(int t, int v) {
	return p[t].num > p[v].num;
}
void init() {
	memset(map, 0, sizeof(map));
	p.clear();
}
void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int py, px, pnum, pdir;
		cin >> py >> px >> pnum >> pdir;
		p.push_back({ py,px,pnum,pdir,i });
	}
}
void chstatus(int id) {
	p[id].num /= 2;
	if (p[id].dir == 1) p[id].dir = 2;
	else if (p[id].dir == 2) p[id].dir = 1;
	else if (p[id].dir == 3) p[id].dir = 4;
	else if (p[id].dir == 4) p[id].dir = 3;
}
void clean(int y, int x) {
	sort(map[y][x].begin(), map[y][x].end(), cmp);
	for (int i = 1; i < map[y][x].size(); i++) {
		p[map[y][x][0]].num += p[map[y][x][i]].num;
		p[map[y][x][i]].num = 0;
	}
}
int getResult() {
	int ans = 0;
	for (int i = 0; i < p.size(); i++) ans += p[i].num;
	return  ans;
}
void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		int sec = 0;
		while (sec < M) {
			memset(map, 0, sizeof(map));
			for (int i = 0; i < p.size(); i++) {
				if (p[i].num == 0) continue;
				p[i].y += drY[p[i].dir];
				p[i].x += drX[p[i].dir];
				if (p[i].y == 0 || p[i].x == 0 || p[i].y == N - 1 || p[i].x == N - 1) chstatus(i);
				map[p[i].y][p[i].x].push_back(i);
			}
			for (int i = 0; i < p.size(); i++) {
				if (p[i].num == 0) continue;
				if (map[p[i].y][p[i].x].size() > 1) {
					clean(p[i].y, p[i].x);
				}
			}
			sec++;
		}
		result = getResult();
		cout << "#" << t << " " << result << "\n";
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
