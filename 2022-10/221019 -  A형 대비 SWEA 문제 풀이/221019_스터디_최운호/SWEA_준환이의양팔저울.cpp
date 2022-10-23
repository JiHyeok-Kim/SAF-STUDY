#include <iostream>
using namespace std;

bool used[9];
int N;
int weight[9];
int answer;
int total;

void init() {
	answer = 0;
	total = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weight[i];
		total += weight[i];
	}
}

int getWay(int num) {
	int temp = 1;

	for (int i = 0; i < num; i++) {
		temp *= 2;
	}
	for (int i = 1; i <= num; i++) {
		temp *= i;
	}

	return temp;
}

void dfs(int lev, int left, int right) {
	if (lev == N) {
		answer++;
		return;
	}

	if (left > total / 2) {
		int way = getWay(N - lev);
		answer += way;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i]) continue;
		used[i] = true;
		if (left >= right + weight[i]) {
			dfs(lev + 1, left, right + weight[i]);
		}
		if (left + weight[i] >= right) {
			dfs(lev + 1, left + weight[i], right);
		}
		used[i] = false;
	}
}

void solve() {
	dfs(0, 0, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();

		solve();

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}