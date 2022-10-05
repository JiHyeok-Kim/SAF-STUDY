#include <iostream>
using namespace std;

int n;
int map[1100];
int dp[1100];

void init() {
	for (int i = 0; i < 1100; i++) {
		map[i] = 0;
		dp[i] = 0;
	}
}
int lsb() {
	int idx = 1;
	int maxi = -1;

	dp[0] = map[0];
	maxi = map[0];
	for (int i = 1; i < n; i++) {
		if (maxi <= map[i]) {
			dp[idx] = map[i];
			maxi = dp[idx];
			idx++;

		}
		else if (maxi > map[i]) {
			
			for (int x = 0; x < idx; x++) {
				if (dp[x] > map[i]) {
					dp[x] = map[i];
					maxi = dp[idx-1];
					break;
				}
			}

		}
	}
	return idx;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> n;
		init();

		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}
		int ans = lsb();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}