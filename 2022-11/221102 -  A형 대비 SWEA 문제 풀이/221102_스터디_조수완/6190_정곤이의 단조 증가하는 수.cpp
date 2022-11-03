#include <iostream>
using namespace std;
int N, result;
int arr[30010];

void input() {
	cin >> N; result = 0;
	for (int i = 0; i < N; i++) cin >> arr[i];
}
bool isValid(int num) {
	int val = num / 10;
	int xval = num % 10;
	if (xval == 0) return  false;
	while (val > 0) {
		int tmp = val % 10;
		if (tmp == 0) return false;
		if (tmp > xval) return false;
		xval = tmp;
		val /= 10;
	}
	return true;
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				int tmp = arr[i] * arr[j];
				if (isValid(tmp)) if (tmp > result) result = tmp;
			}
		}
		if (result == 0)result = -1;
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