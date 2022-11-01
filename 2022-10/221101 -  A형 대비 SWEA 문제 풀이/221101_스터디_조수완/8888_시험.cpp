#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node { int id, cnt, score; };
int N, T, P;
int po[2100], info[2100][2100];
vector<Node> stu;

bool cmp(Node t, Node v) {
	if (t.score != v.score) return t.score > v.score;
	if (t.cnt != v.cnt) return t.cnt > v.cnt;
	return t.id < v.id;
}
void input() {
	cin >> N >> T >> P;
	stu = vector<Node>();
	for (int i = 1; i <= T; i++)po[i] = 0;
	for (int y = 1; y <= N; y++){
		stu.push_back({ y, 0, 0 });
		for (int x = 1; x <= T; x++) {
			cin >> info[y][x];
			if (info[y][x] == 0) {
				po[x]++;
			}
			else {
				stu[y - 1].cnt++;
			}
		}
	}
}
void solve() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		vector<pair<int, int>> p;
		for (int y = 1; y <= N; y++) {
			int score = 0;
			for (int x = 1; x <= T; x++) {
				score += info[y][x] * po[x];
			}
			stu[y - 1].score = score;
		}
		sort(stu.begin(), stu.end(), cmp);
		for (int i = 0; i < N; i++) {
			if (stu[i].id == P) {
				cout << "#" << t << " " << stu[i].score << " " << i + 1 << "\n";
				continue;
			}
		}
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