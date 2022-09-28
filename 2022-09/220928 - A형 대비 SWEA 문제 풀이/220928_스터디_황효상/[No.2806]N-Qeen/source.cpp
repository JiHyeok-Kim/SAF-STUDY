#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;

int N;
int queens_cnt[11];

int row_db[11];
void Nqueens(int deep) {
	if (deep == N) {
		queens_cnt[N]++;
		return;
	}

	for (int a = 0; a < N; ++a) {
		int flag = 1;
		for (int b = 0; b < deep; ++b) {
			if (row_db[b] == a || (b - row_db[b] == deep - a) || (b+row_db[b] == deep + a)) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			row_db[deep] = a;
			Nqueens(deep + 1);
		}
	}
}
void input() {
	for (int a = 1; a <= 10; ++a) {
		N = a;
		Nqueens(0);
	}
	int T;
	cin >> T;
	for (int t = 1; t <= 10; ++t) {
		cin >> N;
		cout << "#"<<t << " " <<queens_cnt[N] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	input();
	return 0;
}
