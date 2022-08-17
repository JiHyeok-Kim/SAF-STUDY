#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int bod_set[60];
int bod_each[60];

int only_set() {
	int cnt = 0;
	int price = 0;
	while (1) {
		if (cnt >= n) break;
		int rest = n - cnt;
		if (rest * bod_each[0] < bod_set[0]) {
			price += rest * bod_each[0];
			break;
		}
		price += bod_set[0];
		cnt += 6;
	}
	return price;
}

int only_each() {
	int cnt = 0;
	int price = 0;
	while (1) {
		if (cnt >= n) break;
		price += bod_each[0];
		cnt++;
	}
	return price;
}

int main() {
	
	int ans;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> bod_set[i] >> bod_each[i];
	}

	sort(bod_set, bod_set + m);
	sort(bod_each, bod_each + m);

	if (bod_set[0] < bod_each[0] * 6) {
		ans = only_set();
	}
	else {
		ans = only_each();
	}
	cout << ans;

	return 0;
}