#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int N;
		int tDays[7] = { 0 };
		int temp[7] = { 0 };
		int idx = 0;
		cin >> N;
		for (int i = 0; i < 7; i++) {
			cin >> tDays[i];
			if (tDays[i] == 1) {
				temp[idx] = i;
				idx++;
			}
		}
		int ans = 21e8;
		for (int i = 0; i < idx; i++) {
			int val = temp[i];
			int result = 0, dayCnt = 0;
			while (dayCnt < N) {
				if (tDays[val % 7] == 1) {
					dayCnt++;
				}
				val++;
				result++;
			}
			ans = min(ans, result);
		}
		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}