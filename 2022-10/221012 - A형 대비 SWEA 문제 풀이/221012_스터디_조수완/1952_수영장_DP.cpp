#include <iostream>
using namespace std;
int T, cost[4], plan[13], result, dp[13];
void input() {
	for (int i = 0; i < 4; i++)cin >> cost[i];
	for (int i = 1; i <= 12; i++) {
		cin >> plan[i];
		dp[i] = 0;
	}
	dp[0] = 0;
}
void simulation() {
	for (int i = 1; i <= 12; i++) {
		if (i <= 2) dp[i] = min(dp[i-1]+plan[i] * cost[0], dp[i-1]+cost[1]);
		else {
			dp[i] = min(dp[i - 1] + plan[i] * cost[0], min(dp[i - 1] + cost[1], dp[i - 3] + cost[2]));
		}
	}
	dp[12] = min(dp[12], cost[3]);
}
void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		simulation();
		result = dp[12];
		cout << "#" << t << " " << result << "\n";
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