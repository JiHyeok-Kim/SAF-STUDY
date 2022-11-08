#include <iostream>
using namespace std;

int N, M, mini;
string map[50];
int W[50], B[50], R[50];
string WBR = "WBR";

void init()
{
	mini = 21e8;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < N; y++) {
			int cnt = 0;
			for (int x = 0; x < M; x++) {
				if (map[y][x] == WBR[i]) continue;
				cnt++;
			}
			if (i == 0) W[y] = cnt;
			else if (i == 1) B[y] = cnt;
			else R[y] = cnt;
		}
	}

	return;
}

int count(int w, int b, int r)
{
	int wbr[3] = { w, w + b, w + b + r };
	int cnt, y;
	cnt = y = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = y; j < wbr[i]; j++) {
			if (i == 0) cnt += W[j];
			else if (i == 1) cnt += B[j];
			else cnt += R[j];
			if (cnt >= mini) return 21e8;
		}
		y = wbr[i];
	}

	return cnt;
}

void solve()
{
	for (int w = 1; w < N - 1; w++) {
		for (int b = 1; b < N - w; b++) {
			int r = N - w - b;
			int cnt = 0;
			mini = min(mini, count(w, b, r));
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
		solve();
		cout << "#" << tc << " " << mini << "\n";
	}

	return 0;
}