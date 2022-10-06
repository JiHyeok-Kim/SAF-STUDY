#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N;
unsigned int in[1000];
int dp[1000];

int Solve() {
	for (int i = 1; i < N; ++i) {
		int mini = 0;
		for (int j = 0; j < i; ++j) {
			if (in[j] <= in[i]) {
				if (mini < dp[j]) mini = dp[j];
			}
		}

		dp[i] += mini;
	}

	int maxi = -1;
	for (int i = 0; i < N; ++i) {
		maxi = max(maxi, dp[i]);
	}
	return maxi;
}

void init() {
	for (int i = 0; i < N; ++i) {
		dp[i] = 1;
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		init();
		for (int i = 0; i < N; ++i) {
			cin >> in[i];
		}

		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}