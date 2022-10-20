#include <iostream>
using namespace std;
int N, result, sum;
int weight[11], used[11];

void input() {
	result = 0;
	sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weight[i];
		sum += weight[i];
	}
}
void dfs(int lev, int left, int right) {
	if (lev == N) result++;

	for (int j = 0; j < N; j++) {
		if (used[j] == 1)continue;
		used[j] = 1;
		if (left + weight[j] > sum / 2) {
			int sum0 = 1;
			for (int i = 1; i < N - lev; i++)sum0 = sum0 * 2 * i;
			result += sum0;
			if (left >= right + weight[j]) dfs(lev + 1, left, right + weight[j]);
			used[j] = 0;
			continue;
		}
		if (left + weight[j] >= right) dfs(lev + 1, left + weight[j], right);
		if (left >= right + weight[j]) dfs(lev + 1, left, right + weight[j]);
		used[j] = 0;
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		dfs(0, 0, 0);
		cout << "#" << t << " " << result << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}