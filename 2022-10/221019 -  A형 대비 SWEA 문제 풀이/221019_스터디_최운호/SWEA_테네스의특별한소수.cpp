#include <iostream>
#include <string>
using namespace std;

char D;
int A, B;

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
	for (int i = 0; i <= 1000000; i++) {
		if (isPrime(i)) memo[i] = true;
	}
}

bool isContain(string num) {
	for (char loop : num) {
		if (loop == D) return true;
	}
	return false;
}

void solve() {
	for (int i = A; i <= B; i++) {
		if (memo[i] == false) continue;
		string num = to_string(i);
		if (isContain(num)) cnt++;
	}
}

int main() {
	int tc;
	cin >> tc;

	primeCheck();

	for (int t = 1; t <= tc; t++) {
		cin >> D >> A >> B;

		cnt = 0;

		solve();

		cout << "#" << t << " " << cnt << '\n';
	}
	return 0;
}