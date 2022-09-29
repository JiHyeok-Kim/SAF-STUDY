#include <iostream>
#include <cmath>
using namespace std;

int T, N;
int queen[10];
int ret;

int CheckPossible(int row) {
	for (int i = 0; i < row; ++i) {
		if (queen[i] == queen[row] || abs(i - row) == abs(queen[i] - queen[row])) {
			return 0;
		}
	}
	return 1;
}

void DFS(int cnt) {
	if (cnt == N) {
		ret++;
		return;
	}

	for (int i = 0; i < N; ++i) {
		queen[cnt] = i;
		if (CheckPossible(cnt)) {
			DFS(cnt + 1);
		}
	}
}

int Solve() {
	ret = 0;
	DFS(0);
	return ret;
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		int res = Solve();
		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}