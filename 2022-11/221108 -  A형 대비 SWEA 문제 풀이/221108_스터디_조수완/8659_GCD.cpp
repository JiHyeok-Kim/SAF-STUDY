#include <iostream>
using namespace std;
long long T, K, arr[91][2];
void mkarr() {
	arr[0][0] = 1; arr[0][1] = 1;
	for (int i = 1; i < 91; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] = arr[i - 1][0];
	}
}
void solve() {
	mkarr();
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> K;
		cout << "#" << t << " " << arr[K][0] << " " << arr[K][1] << "\n";
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