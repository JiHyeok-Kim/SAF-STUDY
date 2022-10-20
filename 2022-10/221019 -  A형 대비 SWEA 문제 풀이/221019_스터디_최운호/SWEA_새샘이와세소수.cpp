#include <iostream>
using namespace std;

int N;
int cnt;

bool memo[1000000];

bool isPrime(int n) {

	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

void primeCheck() {
	for (int i = 0; i < 1000; i++) {
		if (isPrime(i)) memo[i] = true;
	}
}

void find(int lev, int val, int prev) {
	if (lev == 2) {
		if (val < prev) return;
		if (memo[val]) cnt++;
		return;
	}

	for (int i = prev; i < N; i++) {
		if (memo[i] == false) continue;
		find(lev + 1, val - i, i);
	}
}

void solve() {
	find(0, N, 2);
}

int main() {
	int tc;
	cin >> tc;

	primeCheck();

	for (int t = 1; t <= tc; t++) {
		cin >> N;

		cnt = 0;

		solve();

		cout << "#" << t << " " << cnt << '\n';
	}
	return 0;
}