#include <iostream>
using namespace std;

int map[9][9];

bool isRight(int y, int x) {
	int dat[10] = { 0 };
	for (int i = y; i < y+3; i++) {
		for (int j = x; j < x+3; j++) {
			if (dat[map[i][j]] == 1) return false;
			dat[map[i][j]] = 1;
		}
	}

	return true;
}

bool isGood(int y, int x) {
	int dat_col[10] = { 0 };
	int dat_row[10] = { 0 };
	for (int i = 0; i < 9; i++) {
		if (dat_col[map[i][x]] == 1) return false;
		if (dat_row[map[y][i]] == 1) return false;
		dat_col[map[i][x]] = 1;
		dat_row[map[y][i]] = 1;
	}

	return true;
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int flag = 1;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				if (!isRight(i, j)) flag = 0;
			}
		}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (!isGood(i, j)) flag = 0;
			}
		}

		cout << "#" << t << " " << flag << '\n';
	}
	return 0;
}
