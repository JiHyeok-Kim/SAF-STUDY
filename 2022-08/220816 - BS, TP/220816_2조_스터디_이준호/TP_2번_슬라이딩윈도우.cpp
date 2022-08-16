#include <iostream>
using namespace std;

int T, n, w;
int arr[100001];

int firstSum(int idx) {
	int FS = 0;
	for (int i = 0; i < w; i++) {
		FS += arr[i];
	}
	return FS;
}

void pic(int t) {
	int sum = firstSum(0);
	int maxi = -21e7;
	int maxidx = -1;
	for (int i = 0; i <= n - w; i++) {
		if (maxi < sum) {
			maxi = sum;
			maxidx = i;
		}

		if (i == n - w) break;

		sum += arr[i + w];
		sum -= arr[i];
	}

	cout << "#" << t + 1 << " " << maxidx << " " << maxidx + w - 1 << " " << maxi << "\n";
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> w;
		for (int k = 0; k < n; k++) {
			cin >> arr[k];
		}
		pic(i);
	}

}