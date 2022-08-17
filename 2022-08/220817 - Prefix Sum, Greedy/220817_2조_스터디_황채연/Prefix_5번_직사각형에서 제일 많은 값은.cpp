#include <iostream>
#include <string.h>
using namespace std;

int N, Q;
int map[500][500];
int cnt[500][500][10];
int ret_cnt[10];

int returnMaxNum() {
	int candi_max = 0;
	int candi_idx = -1;
	for (int i = 0; i < 10; ++i) {
		if (candi_max < ret_cnt[i]) {
			candi_max = ret_cnt[i];
			candi_idx = i;
		}
	}

	return candi_idx;
}

void Solve(int a, int b, int c, int d) {
	memset(ret_cnt, 0, sizeof(ret_cnt));
	for (int y = a; y <= c; ++y) {
		for (int i = 0; i < 10; ++i) {
			ret_cnt[i] += (cnt[y][d][i] - cnt[y][b - 1][i]);
		}
	}

	return;
}

int main()
{
	cin >> N;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		cnt[y][0][map[y][0]]++;
		for (int x = 1; x < N; ++x) {
			for (int i = 0; i < 10; ++i) {
				cnt[y][x][i] = cnt[y][x - 1][i];
			}
			cnt[y][x][map[y][x]]++;
		}
	}

	cin >> Q;
	while (Q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		Solve(a, b, c, d);
		int ret = returnMaxNum();
		cout << ret << "\n";
	}

	return 0;
}