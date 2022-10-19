#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, K;
int tobni[4][8];

typedef struct {
	int num;
	int d;
}INFO;
vector<INFO> v;

void shift(int idx, int type) {
	int backup[8] = { 0 };
	if (type == 1) {
		int temp = tobni[idx][7];
		for (int i = 1; i < 8; ++i) {
			backup[i] = tobni[idx][i - 1];
		}
		backup[0] = temp;
		memcpy(tobni[idx], backup, sizeof(backup));
	}
	if (type == -1) {
		int temp = tobni[idx][0];
		for (int i = 6; i >= 0; --i) {
			backup[i] = tobni[idx][i + 1];
		}
		backup[7] = temp;
		memcpy(tobni[idx], backup, sizeof(backup));
	}
}

int Solve() {
	int store[4] = { 0 };
	for (int i = 0; i < v.size(); ++i) {
		memset(store, 0, sizeof(store));
		if (v[i].num == 0) {
			store[0] = v[i].d;
			if (tobni[0][2] != tobni[1][6]) {
				store[1] = -v[i].d;
				if (tobni[1][2] != tobni[2][6]) {
					store[2] = v[i].d;
					if (tobni[2][2] != tobni[3][6]) {
						store[3] = -v[i].d;
					}
				}
			}
		}
		if (v[i].num == 1) {
			store[1] = v[i].d;
			if (tobni[0][2] != tobni[1][6]) {
				store[0] = -v[i].d;
			}

			if (tobni[1][2] != tobni[2][6]) {
				store[2] = -v[i].d;
				if (tobni[2][2] != tobni[3][6]) {
					store[3] = v[i].d;
				}
			}
		}
		if (v[i].num == 2) {
			store[2] = v[i].d;
			if (tobni[1][2] != tobni[2][6]) {
				store[1] = -v[i].d;
				if (tobni[0][2] != tobni[1][6]) {
					store[0] = v[i].d;
				}
			}

			if (tobni[2][2] != tobni[3][6]) {
				store[3] = -v[i].d;
			}
		}
		if (v[i].num == 3) {
			store[3] = v[i].d;
			if (tobni[2][2] != tobni[3][6]) {
				store[2] = -v[i].d;
				if (tobni[1][2] != tobni[2][6]) {
					store[1] = v[i].d;
					if (tobni[0][2] != tobni[1][6]) {
						store[0] = -v[i].d;
					}
				}
			}
		}

		for (int i = 0; i < 4; ++i) {
			if (store[i] == 0) continue;
			shift(i, store[i]);
		}
	}

	int sum = 0;
	int multi = 1;
	for (int i = 0; i < 4; ++i) {
		sum += tobni[i][0] * multi;
		multi *= 2;
	}

	return sum;
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> K;
		v.clear();
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 8; ++j) {
				cin >> tobni[i][j];
			}
		}

		for (int i = 0; i < K; ++i) {
			int num, d;
			cin >> num >> d;
			v.push_back({ --num, d });
		}

		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}