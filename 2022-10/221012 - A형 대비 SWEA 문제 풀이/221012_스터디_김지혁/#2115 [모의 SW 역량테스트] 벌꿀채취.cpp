#include <iostream>
#include <cmath>
#include <cmath>
using namespace std;

int N, M, C, maxi, sum;
int map[10][10];

void init()
{
	maxi = sum = 0;
	cin >> N >> M >> C;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	return;
}

void dfs(int temp[5], int lev, int value, int cost)
{
	if (value > C) {
		return;
	}

	if (lev == M) {
		sum = max(sum, cost);
		return;
	}

	for (int i = 0; i < 2; i++) {
		dfs(temp, lev + 1, value + temp[lev] * i, cost + pow(temp[lev], 2) * i);
	}

	return;
}

void cost(int temp[5], int ty, int tx)
{
	sum = 0;
	dfs(temp, 0, 0, 0);
	map[ty][tx] = sum;

	return;
}

void getHoney()
{
	int a, b;
	a = b = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N - M + 1; x++) {
			int temp[5] = { 0 };
			for (int t = 0; t < M; t++) {
				temp[t] = map[y][x + t];
			}
			cost(temp, y, x);
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N - M + 1; x++) {
			a = map[y][x];
			int ty = y, tx = x + M;
			for (int i = ty; i < N; i++) {
				for (int j = tx; j < N; j++) {
					b = map[i][j];
					maxi = max(maxi, a + b);
				}
				tx = 0;
			}
		}
	}

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		getHoney();
		cout << "#" << tc << " " << maxi << "\n";
	}

	return 0;
}