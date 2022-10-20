#include <iostream>
#include <vector>
using namespace std;
int N, result, prime[1000];
vector<int>tong;
void mkprime() {
	prime[1] = 1;
	for (int num = 2; num < 1000; num++) {
		if (prime[num] == 1)continue;
		tong.push_back(num);
		for (int j = num + num; j < 1000; j += num) prime[j] = 1;
	}
}
void input() {
	cin >> N;
	result = 0;
}
void dfs(int lev, int sum, int start) {
	if (lev == 3) {
		if (sum == N) result++;
		return;
	}
	for (int i = start; i < tong.size(); i++) {
		if (sum + tong[i] * (3 - lev) > N) break;
		dfs(lev + 1, sum + tong[i], i);
	}
}
void solve() {
	mkprime();
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		dfs(0, 0, 0);
		cout << "#" << t << " " << result << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}