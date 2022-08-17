#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int six[51];
int one[51];

int getMoney(int type) {
	if (type == 0) {
		int people = n;
		if (n % 6 != 0) people += n % 6;

		return (people / 6) * six[0];
	}

	else if (type == 1) return n * one[0];
	else {
		int cnt = 0;
		cnt += (n / 6) * six[0];
		int remain = n % 6;
		cnt += remain * one[0];

		return cnt;
	}
	
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> six[i] >> one[i];
	}

	sort(six, six + m);
	sort(one, one + m);

	int sol[3];
	for (int i = 0; i < 3; i++) {
		sol[i] = getMoney(i);
	}

	int min = 21e8;
	for (int i = 0; i < 3; i++) {
		if (min > sol[i]) min = sol[i];
	}

	cout << min;

	return 0;
}