#include <iostream>
using namespace std;

int n, m;

int arr[10000];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int st = 1;
	int result = 0;
	while (st <= n) {
		int sum = 0;
		for (int i = 0; i < st; i++) {
			sum += arr[i];
		}

		for (int i = 0; i <= n - st; i++) {
			if (sum == m) result++;
			if (i == n - st) break;
			sum += arr[i + st];
			sum -= arr[i];
		}
		st++;
	}

	cout << result;

	return 0;
}