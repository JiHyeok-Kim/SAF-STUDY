#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	double score;
	int idx;
};
bool cmp(Node t, Node v) {
	return t.score > v.score;
}
vector<Node> p;
int N, K, result;
char grade[10][3] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };
void input() {
	p.clear();
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		double score = 0.35 * a + 0.45 * b + 0.2 * c;
		p.push_back({ score,i });
	}
}
void solution(int t) {
	sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < N; i++) {
		if (p[i].idx == K - 1) {
			cout << "#" << t << " " << grade[i/(N/10)] << "\n";
			return;
		}
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		solution(t);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}