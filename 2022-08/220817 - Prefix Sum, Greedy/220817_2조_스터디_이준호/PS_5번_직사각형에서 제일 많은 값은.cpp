#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[500][500];
int q;
int a, b, c, d;
int sumA[500][500][10];

void findmini(int a, int b, int c, int d) {
	int ans[10] = { 0 };
	for (int k = 1; k < 10; k++) {
		ans[k] = sumA[c][d][k];
		ans[k] -= sumA[a - 1][d][k];
		ans[k] -= sumA[c][b - 1][k];
		ans[k] += sumA[a - 1][b - 1][k];
	}

	int maxs = 0;
	int maxidx;
	for (int k = 1; k < 10; k++) {
		if (maxs < ans[k]) {
			maxs = ans[k];
			maxidx = k;
		}
	}
	cout << maxidx << "\n";
}

int main() {
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> arr[y][x];
		}
	}

	for (int y = 1; y < n; y++) {
		for (int x = 1; x < n; x++) {
			sumA[y][x][arr[y][x]]++;
			for (int k = 1; k < 10; k++) {
				sumA[y][x][k] += sumA[y - 1][x][k];
				sumA[y][x][k] += sumA[y][x - 1][k];
				sumA[y][x][k] -= sumA[y - 1][x - 1][k];
			}
		}
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c >> d;
		findmini(a, b, c, d);
	}

	return 0;
}