#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node { int y, x, num, dir, id, sec; };
vector<Node> p;
vector<int> map[110][110];
int N, K, M, result;
int drY[5] = { 0,-1,1,0,0 };//»óÇÏÁÂ¿ì
int drX[5] = { 0,0,0,-1,1 };
bool cmp (int t, int v) { return p[t].num > p[v].num; };
void input() {
	cin >> N >> M >> K;
	result = 0;
	p.clear();
	for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) map[y][x].clear();
	for (int i = 0; i < K; i++) {
		int ty, tx, num, dir;
		cin >> ty >> tx >> num >> dir;
		p.push_back({ ty,tx,num,dir,i,0 });
		map[ty][tx].push_back(i);
	}
}
void changeVal(int idx) {
	p[idx].num /= 2;
	if (p[idx].num == 0) map[p[idx].y][p[idx].x].clear();
	if (p[idx].dir == 1) p[idx].dir = 2;
	else if (p[idx].dir == 2) p[idx].dir = 1;
	else if (p[idx].dir == 3) p[idx].dir = 4;
	else if (p[idx].dir == 4) p[idx].dir = 3;
}
void cmpP(int ty, int tx) {
	int u = 0;
	sort(map[ty][tx].begin(), map[ty][tx].end(), cmp);
	for (int i = 1; i < map[ty][tx].size(); i++) {
			p[map[ty][tx][0]].num += p[map[ty][tx][i]].num;
			p[map[ty][tx][i]].num = 0;
	}
	for (int i = map[ty][tx].size() - 1; i > 0; i--) {
		map[ty][tx].erase(map[ty][tx].begin() + i);
	}
}
void findResult() {
	for (int i = 0; i < K; i++) result += p[i].num;
}
void solution() {
	int sec = 1;
	while (1) {
		for (int i = 0; i < K; i++) {
			if (p[i].num <= 0) continue;
			for (int j = 0; j < map[p[i].y][p[i].x].size(); j++) {
				if (p[i].id == map[p[i].y][p[i].x][j]) map[p[i].y][p[i].x].erase(map[p[i].y][p[i].x].begin() + j);
			}
			p[i].y = p[i].y + drY[p[i].dir];
			p[i].x = p[i].x + drX[p[i].dir];
			p[i].sec++;
			map[p[i].y][p[i].x].push_back({ p[i].id });
			if (p[i].y <= 0 || p[i].y >= N - 1 || p[i].x <= 0 || p[i].x >= N - 1) changeVal(i);
		}
		for (int i = 0; i < K; i++) {
			if (p[i].num == 0)continue;
			if (map[p[i].y][p[i].x].size() > 1) cmpP(p[i].y, p[i].x);
		}
		if (sec == M) break;
		sec++;
	}
	findResult();
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		solution();
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