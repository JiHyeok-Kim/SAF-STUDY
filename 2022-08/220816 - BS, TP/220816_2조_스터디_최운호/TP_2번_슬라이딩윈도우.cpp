#include <iostream>
using namespace std;

int t;

int main() {

	cin >> t;

	for (int testCase = 1; testCase <= t; testCase++) {
		int n, w;
		cin >> n >> w;

		int arr[100000] = { 0, };
		int sum = 0;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int maxSum = -21e8;
		int maxS = 0, maxE = 0;

		for (int i = 0; i < w; i++) {
			sum += arr[i];
		}

		for (int i = 0; i <= n - w; i++) {
			if (maxSum < sum) {
				maxSum = sum;
				maxS = i;
				maxE = i + w - 1;
			}
			if (i == n - w) break;

			sum += arr[i + w];
			sum -= arr[i];
		}

		cout << "#" << testCase << " " << maxS << " " << maxE << " " << maxSum << '\n';
	}

	return 0;
}