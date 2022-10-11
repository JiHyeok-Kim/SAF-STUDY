#include <iostream>
using namespace std;
int N, M, result, cost[110];
char ansnum[110][9], mynum[1100][9];

void init() {
	result = 0;
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 8; j++) cin >> ansnum[i][j];
		cin >> cost[i];
	}
	for (int i = 0; i < M; i++) for (int j = 0; j < 8; j++) cin >> mynum[i][j];
}
int isFit(int ans, int my) {
	for (int i = 0; i < 8; i++) {
		if (ansnum[ans][i] == '*')continue;
		if (ansnum[ans][i] != mynum[my][i]) return 0;
	}
	return 1;
}
void findResult() {
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		int flag = isFit(i, j);
		if (flag) result += cost[i];
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t ++ ) {
		init();
		input();
		findResult();
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