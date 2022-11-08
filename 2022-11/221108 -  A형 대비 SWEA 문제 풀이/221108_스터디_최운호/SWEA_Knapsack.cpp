#include <iostream>
#include <algorithm>
using namespace std;


int N, K;
int w[101], c[101];
void init()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> c[i];
	}
}

void solve(int t) {
	int dp[101][1001] = { 0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (w[i] > j) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j - w[i]] + c[i], dp[i - 1][j]);
			}
		}
	}

	cout << "#" << t << " " << dp[N][K] << '\n';
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();
		solve(t);
	}
	return 0;
}