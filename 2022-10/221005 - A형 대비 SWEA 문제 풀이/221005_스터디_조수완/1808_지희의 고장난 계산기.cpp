#include <iostream>
using namespace std;
int T, num[10], result, X, nums[1100000];

void input() {
	for (int i = 0; i < 10; i++) cin >> num[i];
	cin >> X;
	for (int i = 0; i <= X; i++)nums[i] = 0;
	result = 21e8;
}
void makeNum(int lev, int xnum) {
	if (lev > 7) return;
	if (xnum > X) return;

	if (lev > 0) nums[xnum] = lev;

	for (int i = 0; i < 10; i++) {
		if (num[i] == 0)continue;
		makeNum(lev + 1, xnum * 10 + i);
	}
}
void findResult() {
	int cnt = 0;
	int temp = X;
	for (int i = X; i > 1; i--) {
		while (nums[i] > 0) {
			if (temp % i == 0) {
				cnt += 1 + nums[i];
				temp /= i;
			}
			else break;
		}
		if (temp == 1) {
			result = cnt;
			break;
		}
	}
}
void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		if (X == 1 && num[1] == 1) result = 2;
		else {
			makeNum(0, 0);
			findResult();
		}
		if (result == 21e8) result = -1;
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