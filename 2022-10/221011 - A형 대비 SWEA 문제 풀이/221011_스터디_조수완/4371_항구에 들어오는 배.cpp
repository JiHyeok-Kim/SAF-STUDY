#include <iostream>
using namespace std;
int N, good[5100], used[5001];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> good[i];
		used[i] = 0;
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		int cnt = 1, result = 0;
		used[0] = 1;
		while (cnt <= N) {
			for (int i = 1; i < N; i++) {
				if (used[i] == 1) continue;
				int term = good[i] - good[0];
				int xval = good[i];
				used[i] = 1;
				cnt++;
				result++;
				for (int j = i + 1; j < N; j++) {
					if (good[j] - xval == term) {
						if (used[j] == 0) cnt++;
						xval = good[j];
						used[j] = 1;
					}
					if (cnt == N) break;
				}
				if (cnt == N) break;
			}
			if (cnt == N) break;
		}
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