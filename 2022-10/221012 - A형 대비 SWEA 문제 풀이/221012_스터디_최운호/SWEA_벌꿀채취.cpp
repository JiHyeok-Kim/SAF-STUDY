#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, c;
int map[10][10];
int honey[2][5];
int maxVal;
int firstMax;
int secondMax;
int used[5];

bool canSelect(int y, int x, int size) {
	if (x + size > n) return false;

	return true;
}

void useH(int y, int x, int size, int lev) {
	for (int i = 0; i < size; i++) {
		honey[lev][i] = map[y][x + i];
	}
}

void getFirstMax(int lev, int val, int cost, int s) {
	for (int i = s; i < m; i++) {
		if (val + honey[0][i] > c) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		getFirstMax(lev + 1, val + honey[0][i], cost + (honey[0][i]*honey[0][i]), i);
		used[i] = 0;
	}

	firstMax = max(cost, firstMax);
	return;
}

void getSecondMax(int lev, int val, int cost, int s) {
	for (int i = s; i < m; i++) {
		if (val + honey[1][i] > c) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		getSecondMax(lev + 1, val + honey[1][i], cost + honey[1][i]*honey[1][i], i);
		used[i] = 0;
	}

	secondMax = max(cost, secondMax);
	return;
}

void sell() {
	firstMax = 0;
	secondMax = 0;

	getFirstMax(0, 0, 0, 0);
	getSecondMax(0, 0, 0, 0);

	maxVal = max(firstMax + secondMax, maxVal);
}

void select(int lev, int sY, int sX) {
	if (lev == 2) {
		sell();
		return;
	}

	for (int i = sY; i < n; i++) {
		for (int j = sX; j < n; j++) {
			if (canSelect(i,j,m)) {
				useH(i, j, m, lev);
				select(lev + 1, i, j+m);
			}
		}
		sX = 0;
	}
}

int main() {

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m >> c;
		maxVal = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		select(0,0,0);

		cout << "#" << t << " " << maxVal << '\n';
	}

	return 0;
}