#include <iostream>
using namespace std;

int n, m;
int map[20][20];
int maxVal;
int cnt;

int getHome(int y, int x, int k) {
	int a = 0;
	int homes = 0;
	
	for (int i = y - k + 1; i < y + k; i++) {
		for (int j = x - a; j <= x + a; j++) {
			if (i < 0 || j < 0 || i >= n || j >= n) continue;
			if (map[i][j] == 1) homes++;
		}
		if (i < y) a++;
		else a--;
	}

	return homes;
}

void getCost() {
	int k = 1;

	while (1) {
		int cost = (k * k) + ((k - 1) * (k - 1));
		if (cost >= (cnt * m)) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int homes = getHome(i, j, k);
				if (homes * m >= cost) maxVal = max(maxVal, homes);
			}
		}

		k++;
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		maxVal = 0;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) cnt++;
			}
		}

		getCost();

		cout << "#" << t << " " << maxVal << '\n';
	}
	return 0;
}