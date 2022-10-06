#include <iostream>
#include <cstring>
using namespace std;
int T, N, nums[1100], used[1100], result;

void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		memset(used, 0, sizeof(used));
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
			used[nums[i]]++;
		}
		int flag = 0;
		for (int i = 0; i < 10; i++) {
			if (used[i] == 0) {
				result = i;
				flag = 1;
				break;
			}
		}
		if (!flag && N > 1) {
			for (int i = 0; i < N - 1; i++) {
				int temp = nums[i] * 10 + nums[i + 1];
				used[temp]++;
			}
			for (int i = 10; i < 100; i++) {
				if (used[i] == 0) {
					result = i;
					flag = 1;
					break;
				}
			}
		}
		if (!flag && N > 2) {
			for (int i = 0; i < N - 2; i++) {
				int temp = nums[i] * 100 + nums[i + 1] * 10 + nums[i + 2];
				used[temp]++;
			}
			for (int i = 100; i < 1000; i++) {
				if (used[i] == 0) {
					result = i;
					flag = 1;
					break;
				}
			}
		}
		cout << "#" << t << " " << result << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}