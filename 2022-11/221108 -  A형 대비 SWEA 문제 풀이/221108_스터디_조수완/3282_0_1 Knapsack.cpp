#include <iostream>
#include <cstring>
using namespace std;
int N, K;
int v[101], c[101];
int dp[101][1001];

void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(dp, 0, sizeof(dp));
		cin >> N >> K;
		for (int i = 0; i < N; i++) cin >> v[i] >> c[i];
		for (int i = v[0]; i <= K; i++) dp[0][i] = c[0];
		for (int i = 1; i < N; i++) {
			for (int j = 0; j <= K; j++) {
				if (j < v[i]) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = max(dp[i - 1][j - v[i]] + c[i], dp[i - 1][j]);
			}
		}
		cout << "#" << t << " " << dp[N - 1][K] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}