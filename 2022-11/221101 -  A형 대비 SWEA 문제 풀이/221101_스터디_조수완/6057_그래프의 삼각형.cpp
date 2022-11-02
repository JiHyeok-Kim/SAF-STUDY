#include <iostream>
using namespace std;
int N, M, result, amat[55][55];
int used[55];

void input() {
	result = 0;
	cin >> N >> M;
	for (int y = 0; y < N; y++)for (int x = 0; x < N; x++)amat[y][x] = 0;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		amat[from - 1][to - 1] = 1;
		amat[to - 1][from - 1] = 1;
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		for (int i = 0; i < N-2; i++) {
			for (int j = i + 1; j < N-1; j++) {
				for (int k = j + 1; k < N; k++) {
					if (amat[i][j] && amat[j][k] && amat[k][i]) result++;
				}
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