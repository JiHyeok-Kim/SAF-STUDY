#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[16][16];
int used[16];
int minVal = 21e8;
int n;
int foodCnt;


void run() {
	vector<int> f1;
	vector<int> f2;

	int a = 0;
	int b = 0;

	for (int i = 0; i < n; i++) {
		if (used[i] == 1) f1.push_back(i);
		else f2.push_back(i);
	}

	for (int i = 0; i < foodCnt; i++) {
		for (int j = 0; j < foodCnt; j++) {
			if (i == j) continue;
			a += map[f1[i]][f1[j]] + map[f1[j]][f1[i]];
			b += map[f2[i]][f2[j]] + map[f2[j]][f2[i]];
		}
	}

	minVal = min(minVal, abs(a - b));

	return;
}

void dfs1(int lev, int prev) {
	if (lev == foodCnt) {
		run();
		return;
	}

	for (int i = prev; i < n - (foodCnt - lev); i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		dfs1(lev + 1, i);
		used[i] = 0;
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		minVal = 21e8;

		foodCnt = n / 2;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		dfs1(0, 0);

		cout << "#" << t << " " << minVal / 2 << '\n';
	}

	return 0;
}