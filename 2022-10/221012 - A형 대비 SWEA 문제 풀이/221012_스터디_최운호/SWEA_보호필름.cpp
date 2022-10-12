#include <iostream>
using namespace std;

struct info {
	int tar;
	int type;
};

int d, w, k;
int film[13][20];
int temp[13][20];
int result = 21e8;
int flag = 0;

void copy() {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < w; j++) {
			temp[i][j] = film[i][j];
		}
	}

	return;
}

bool check(int lev, info arr[20]) {
	copy();

	for (int i = 0; i < lev; i++) {
		for (int j = 0; j < w; j++) {
			temp[arr[i].tar][j] = arr[i].type;
		}
	}

	for (int row = 0; row < w; row++) {
		int flag = 0;
		for (int col = 0; col < d - k + 1; col++) {
			int ret = 1;
			int st = temp[col][row];
			for (int x = col + 1; x < col + k; x++) {
				if (st != temp[x][row]) {
					ret = 0;
					break;
				}
			}
			if (ret) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) return false;
	}

	return true;
}

void dfs(int prev, int lev, info arr[20]) {
	if (lev >= result) return;

	if (prev == d || lev == k || check(lev, arr)) {
		result = min(lev, result);
		return;
	}

	for (int i = prev + 1; i < d; i++) {
		for (int j = 0; j < 2; j++) {
			arr[lev].tar = i;
			arr[lev].type = j;
			dfs(i, lev + 1, arr);
			arr[lev].tar = 0;
			arr[lev].type = j;
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> d >> w >> k;
		result = 21e8;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> film[i][j];
				temp[i][j] = film[i][j];
			}
		}

		info aa[20] = { 0 };

		dfs(-1, 0, aa);

		cout << "#" << t << " " << result << '\n';
	}

	return 0;
}