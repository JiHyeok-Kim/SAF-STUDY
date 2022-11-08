#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct info
{
	int W;
	int B;
	int R;
};

char flag[50][50];
info color[50];
int N, M;
int answer = 21e8;

void dfs(int lev, int idx, int val, int blue) {
	if (idx == N - 1) {
		if (blue == 0) return;
		answer = min(val, answer);
		return;
	}

	if (lev == 0) {
		for (int i = 0; i < 2; i++) {
			int tmp = 0;
			if (i == 0) {
				tmp = color[idx].B + color[idx].R;
				dfs(i, idx + 1, val + tmp, blue);
			}
			else {
				tmp = color[idx].W + color[idx].R;
				dfs(i, idx + 1, val + tmp, 1);
			}
		}
	}
	else if (lev == 1) {
		for (int i = 1; i <= 2; i++) {
			int tmp = 0;
			if (i == 1) {
				tmp = color[idx].R + color[idx].W;
				dfs(i, idx + 1, val + tmp, 1);
			}
			else if (i == 2) {
				tmp = color[idx].W + color[idx].B;
				dfs(i, idx + 1, val + tmp, blue);
			}
		}
	}
	else if (lev == 2) {
		int tmp = color[idx].W + color[idx].B;
		dfs(2, idx + 1, val + tmp, blue);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M;
		answer = 21e8;
		for (int i = 0; i < N; i++) {
			color[i].R = 0;
			color[i].W = 0;
			color[i].B = 0;
			string str;
			cin >> str;
			for (int j = 0; j < M; j++) {
				flag[i][j] = str[j];
				if (flag[i][j] == 'W') color[i].W++;
				else if (flag[i][j] == 'B') color[i].B++;
				else color[i].R++;
			}
		}

		int start = 0;

		start += color[0].B + color[0].R;
		start += color[N - 1].W + color[N - 1].B;

		dfs(0, 1, start, 0);

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}