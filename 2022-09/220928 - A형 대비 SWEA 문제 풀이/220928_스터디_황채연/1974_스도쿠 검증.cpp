#include <iostream>
#include <cstring>
using namespace std;

int T;
int MAP[9][9];
int DAT[10];

bool isValid(int ty, int tx) {
	for (int y = ty; y < ty + 3; ++y) {
		for (int x = tx; x < tx + 3; ++x) {
			int target = MAP[y][x];
			DAT[target]++;
			if (DAT[target] > 1) return false;
		}
	}
	return true;
}

int Solve() {
	for (int y = 0; y < 9; ++y) {
		memset(DAT, 0, sizeof(DAT));
		for (int x = 0; x < 9; ++x) {
			int target = MAP[y][x];
			DAT[target]++;
			if (DAT[target] > 1) return 0;
		}
	}

	for (int x = 0; x < 9; ++x) {
		memset(DAT, 0, sizeof(DAT));
		for (int y = 0; y < 9; ++y) {
			int target = MAP[y][x];
			DAT[target]++;
			if (DAT[target] > 1) return 0;
		}
	}

	for (int y = 0; y < 9; y += 3) {
		for (int x = 0; x < 9; x += 3) {
			memset(DAT, 0, sizeof(DAT));
			if (!isValid(y, x)) return 0;
		}
	}

	return 1;
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		for (int y = 0; y < 9; ++y) {
			for (int x = 0; x < 9; ++x) {
				cin >> MAP[y][x];
			}
		}

		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}