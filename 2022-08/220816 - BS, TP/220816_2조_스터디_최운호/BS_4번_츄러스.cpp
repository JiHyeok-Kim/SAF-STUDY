#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> snack;
int maxVal;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int len;
		cin >> len;
		snack.push_back(len);
	}
	sort(snack.begin(), snack.end());

	int s = 0;
	int e = snack[n - 1];

	if (n == k) {
		cout << snack[0];
		return 0;
	}

	while (s <= e) {
		int mid = (s + e) / 2;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += snack[i] / mid;
		}

		if (cnt >= k) {
			if (maxVal < mid) maxVal = mid;
			s = mid + 1;
		}
		if (cnt < k) e = mid - 1;
	}

	cout << maxVal;

	return 0;
}