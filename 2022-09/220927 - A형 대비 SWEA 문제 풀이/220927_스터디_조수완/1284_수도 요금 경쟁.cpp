#include <iostream>
using namespace std;

int P, Q, R, S, W, result;

void calcA() {
	int bill = W * P;
	result = min(result, bill);
}
void calcB() {
	int bill = 0;
	if (W <= R) bill = Q;
	else {
		bill = (W - R) * S + Q;
	}
	result = min(result, bill);
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> P >> Q >> R >> S >> W;
		result = 21e8;
		calcA();
		calcB();
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