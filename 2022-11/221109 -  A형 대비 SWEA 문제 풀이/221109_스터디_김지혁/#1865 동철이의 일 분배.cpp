#include <iostream>
#include <cstring>
using namespace std;

int N;
double ans;
int map[16][16];
int mapMax[16];
bool used[16];

void init()
{
	ans = 0;
	memset(mapMax, 0, sizeof(mapMax));

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			mapMax[j] = max(mapMax[j], map[i][j]);
		}
	}

	return;
}

void DFS(int lev, double pcnt)
{
	if (lev == N) {
		ans = max(ans, pcnt);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == true) continue;
		double n = map[i][lev];
		double temp = pcnt;
		for (int j = lev; j < N; j++) {
			double t = mapMax[j];
			temp *= t / 100;
		}
		if (temp <= ans) return;
		used[i] = true;

		DFS(lev + 1, pcnt * n / 100);

		used[i] = false;
	}

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout.precision(6);
	cout << fixed;

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		DFS(0, 1);
		ans *= 100;
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}