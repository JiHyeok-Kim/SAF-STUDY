#include <iostream>
using namespace std;

int arr[100001];
int line[100001];

int getSum(int b, int m, int c) {
	int sum = 0;
	if (b < m && b < c) {
		return ((line[m - 1]) + (line[c - 1]) - arr[c]);
	}
	else if (b > m && b > c) {
		return ((line[b] - line[m]) + (line[b] - line[c]) - arr[c]);
	}
	else if (b > c && b < m) {
		return ((line[m - 1] - line[b - 1]) + (line[b] - line[c]));
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	line[0] = arr[0];
	for (int i = 1; i < n; i++) {
		line[i] = line[i - 1] + arr[i];
	}

	int basket[3];
	basket[0] = 0;
	basket[1] = n / 2;
	basket[2] = n - 1;
	int min[3];
	min[0] = n - 1;
	min[1] = n - 1;
	min[2] = 0;
	int maxVal = 0;

	for (int i = 0; i < 3; i++) {
		int b = basket[i];
		int m = min[i];
		int c = 0;
		for (int j = 0; j < n; j++) {
			if (j == b || j == m) continue;
			c = j;
			if (i == 1) c = 0;

			int sum = getSum(b, m, c);

			if (sum > maxVal) maxVal = sum;
		}
	}

	cout << maxVal;

	return 0;
}