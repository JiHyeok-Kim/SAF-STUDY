#include <iostream>
using namespace std;
int T, N;
int arr[20][20];
float dp[20][20];
int used[20][20][16];
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int y = 0; y < N; y++)for (int x = 0; x < N; x++)cin >> arr[y][x];
		for (int i = 0; i < N; i++)dp[i][0] = arr[i][0] / 100;
		for (int x = 1; x < N; x++)for (int y = 0; y < N; y++) {
			int maxidx = 0; float maxi = 0.0;
			for (int i = 0; i < N; i++) {
				if (used[y][x - 1][i] == 1) { used[y][x][i] == 1; continue; }
				float tmp = (arr[y][x] / 100) * dp[i][x] * 10;
				if (tmp > maxi) {
					maxi = tmp;
					maxidx = i;
				}
				dp[y][x] = maxi;
				used[y][x][maxidx] = 1;
			}
		}
		float result = 0;
		for (int i = 0; i < N; i++) if (result > dp[i][N - 1]) result = dp[i][N - 1];
		cout << "#" << t << result << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cout << fixed;
	cout.precision(6);
	solve();
	return 0;
}