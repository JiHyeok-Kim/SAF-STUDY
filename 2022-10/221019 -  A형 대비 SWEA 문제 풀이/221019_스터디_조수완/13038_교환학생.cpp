#include <iostream>
#include <vector>
using namespace std;
int n, result, week[7], cnt;
vector<int> start;

void input() {
	start.clear();
	cnt = 0;
	cin >> n;
	for (int i = 0; i < 7; i++) {
		cin >> week[i];
		if (week[i] == 1) {
			start.push_back(i);
			cnt++;
		}
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		if (cnt == 1) result = 1 + (n - 1) * 7;
		else {
			result = 21e8;
			int cnt0 = 0, result0 = n / cnt * 7;
			if (n % cnt == 0) {
				for (int j = 0; j < start.size(); j++) {
					cnt0 = 0;
					for (int i = 0; i < 7; i++) {
						if (week[(start[j] - i - 1 + 7) % 7] == 1) break;
						if (week[(start[j] - i - 1 + 7) % 7] == 0) cnt0++;
					}
					result = min(result, result0 - cnt0);
				}
			}
			else {
				result = 21e8;
				int temp = 0, cnt0 = 0, result0 = n / cnt * 7;
				for (int j = 0; j < start.size(); j++) {
					temp = n % cnt;
					cnt0 = 0;
					for (int i = 0; i < 7; i++) {
						if (temp == 0) break;
						cnt0++;
						if (week[(start[j] + i) % 7] == 1) temp--;
					}
					result = min(result, result0 + cnt0);
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