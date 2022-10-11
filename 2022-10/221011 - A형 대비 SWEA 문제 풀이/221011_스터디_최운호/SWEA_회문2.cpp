#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char map[100][100];
int maxLen;

int getRowPD(int y, int x) {
	int maxSize = 100 - x;
	for (int size = maxSize; size >= 2; size--) {
		int flag = 1;
		for (int i = 0; i < size / 2; i++) {
			if (map[y][x + i] != map[y][x + size - 1 - i]) {
				flag = 0;
				break;
			}
		}
		if (flag) return size;
	}

	return 1;
}

int getColPD(int y, int x) {
	int maxSize = 100 - y;
	for (int size = maxSize; size >= 2; size--) {
		int flag = 1;
		for (int i = 0; i < size / 2; i++) {
			if (map[y + i][x] != map[y + size - 1 - i][x]) {
				flag = 0;
				break;
			}
		}
		if (flag) return size;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int t = 1; t <= 10; t++) {
		int n;
		cin >> n;
		maxLen = 0;
		for (int i = 0; i < 100; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < 100; j++) {
				map[i][j] = str[j];
			}
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				int rowVal = getRowPD(i, j);
				int colVal = getColPD(i, j);
				int maxi = max(rowVal, colVal);
				maxLen = max(maxLen, maxi);
			}
		}
		cout << "#" << n << " " << maxLen << '\n';
	}
	return 0;
}