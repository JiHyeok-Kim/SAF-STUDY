#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int N;
int map[10][10];


bool row_checker() {
	int used[10] = { 0 };
	for (int a = 0; a < 9; ++a) {
		for (int b = 0; b < 9; ++b) {
			if (used[map[a][b]] == a + 1) {
				return 1;
			}
			used[map[a][b]]++;
		}
	}
	return 0;
}

bool col_checker() {
	int used[10] = { 0 };
	for (int b = 0; b < 9; ++b) {
		for (int a = 0; a < 9; ++a) {
			if (used[map[a][b]] == b + 1) {
				return 1;
			}
			used[map[a][b]]++;
		}
	}

	return 0;
}

bool temp_checker(int x, int y) {
	int used[10] = { 0 };
	for (int a = 0; a < 3; ++a) {
		int nx = x + a;
		for (int b = 0; b < 3; ++b) {
			int ny = y + b;
			if (used[map[nx][ny]] == 1)
				return 1;
			++used[map[nx][ny]];
		}
	}
	return 0;
}
bool last_checker() {
	for (int a = 0; a < 9; a += 3) {
		for (int b = 0; b < 9; b += 3) {
			if (temp_checker(a, b))
				return 1;
		}
	}
	return 0;
}
void input() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		for (int a = 0; a < 9; ++a) {
			for (int b = 0; b < 9; ++b) {
				cin >> map[a][b];
			}
		}
		cout << "#" << t << " ";
		if (row_checker()) {
			cout << 0 << "\n";
			continue;
		}
		if (col_checker()) {
			cout << 0 << "\n";
			continue;
		}
		if (last_checker()) {
			cout << 0 << "\n";
			continue;
		}
		cout << 1 << "\n";

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
	input();
	return 0;
}
