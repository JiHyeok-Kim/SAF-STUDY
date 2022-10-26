#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int choco[50][50];
int N, M;
int minVal = 21e8;
int prefix[51][51];
int memo[51][51][51][51];

void input()
{
	memset(prefix, 0, sizeof(prefix));
	memset(memo, -1, sizeof(memo));
	minVal = 21e8;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> choco[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + choco[i-1][j-1];
		}
	}
}

int getDP(int r, int c, int H, int W) {
	if (H * W == 1) return 0;
	if (memo[r][c][H][W] != -1) return memo[r][c][H][W];

	int ret = 21e8;

	int sum = prefix[r + H][c + W] + prefix[r][c] - prefix[r + H][c] - prefix[r][c + W];

	for (int i = 1; i < W; i++) {
		ret = min(ret, sum + getDP(r, c, H, i) + getDP(r, c + i, H, W - i));
	}
	for (int i = 1; i < H; i++) {
		ret = min(ret, sum + getDP(r, c, i, W) + getDP(r + i, c, H - i, W));
	}

	memo[r][c][H][W] = ret;
	return ret;
}

void solve(int t) {
	int result = getDP(0,0,N,M);

	cout << "#" << t << " " << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();

		solve(t);
	}
	return 0;
}