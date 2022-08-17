#include <iostream>
#include <vector>
using namespace std;
struct DAT {
	int dat[10] = { 0, };
};

DAT v[501][501];

int n;
int arr[501][501];

int getCount(int y1, int x1, int y2, int x2) {
	DAT result;
	for (int i = 0; i < 10; i++) {
		result.dat[i] += v[y1][x1].dat[i];
		result.dat[i] += v[y2 - 1][x2 - 1].dat[i];
		result.dat[i] -= v[y1][x2 - 1].dat[i];
		result.dat[i] -= v[y2 - 1][x1].dat[i];
	}
	int max = 0;
	int maxNum = 0;

	for (int i = 0; i < 10; i++) {
		if (max < result.dat[i]) {
			max = result.dat[i];
			maxNum = i;
		}
	}

	return maxNum;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][0] == j) v[i][0].dat[j]++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			for (int k = 0; k < 10; k++) {
				v[i][j].dat[k] = v[i][j - 1].dat[k];
				if (arr[i][j] == k) v[i][j].dat[k]++;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 10; k++) {
				v[i][j].dat[k] += v[i - 1][j].dat[k];
			}
		}

	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int result = getCount(y2, x2, y1, x1);

		cout << result << '\n';
	}
	
	return 0;
}