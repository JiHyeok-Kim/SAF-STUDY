#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;


int map[15][15];
int N, M;

int row_cnt() {
	int ans = 0;
	for (int a = 0; a < N; ++a) {
		int cnt = 0;
		for (int b = 0; b < N; ++b) {
			if (map[a][b] == 1)
				++cnt;
			else {
				if (cnt > 0) {
					if (cnt == M)
						++ans;
					cnt = 0;
				}
			}
		}
		if (cnt == M)
			++ans;
	}

	return ans;

}

int col_cnt() {
	int ans = 0;
	for (int a = 0; a < N; ++a) {
		int cnt = 0;
		for (int b = 0; b < N; ++b) {
			if (map[b][a] == 1)
				++cnt;
			else {
				if (cnt > 0) {
					if (cnt == M)
						++ans;
					cnt = 0;
				}
			}
		}
		if (cnt == M)
			++ans;
	}

	return ans;

}
void input() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N >> M;
		memset(map, 0, sizeof(map));
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < N; ++b) {
				cin >> map[a][b];
			}
		}
		cout << "#" << t << " " << row_cnt() + col_cnt()<<"\n";
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
