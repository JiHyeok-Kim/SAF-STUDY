#include <iostream>
#include <cstring>
using namespace std;
int T, N, M, result;
char flag[51][51];
int dat[51][130];

void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(dat, 0, sizeof(dat));
		cin >> N >> M;
		for (int y = 0; y < N; y++){
			for (int x = 0; x < M; x++) {
				cin >> flag[y][x]; dat[y][flag[y][x]]++;
			}
			if (y != 0) {
				dat[y]['W'] += dat[y - 1]['W'];
				dat[y]['B'] += dat[y - 1]['B'];
				dat[y]['R'] += dat[y - 1]['R'];
			}
		}
		result = 21e8;
		for (int i = 0; i < N - 2; i++) {
			for (int j = i + 1; j < N - 1; j++) {
				int cnt = 0;
				cnt += dat[i]['W'];
				cnt += (dat[j]['B'] - dat[i]['B']);
				cnt += (dat[N - 1]['R'] - dat[j]['R']);
				if (result > (N * M - cnt)) result = (N * M - cnt);
			}
		}
		cout << "#" << t << " " << result << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}