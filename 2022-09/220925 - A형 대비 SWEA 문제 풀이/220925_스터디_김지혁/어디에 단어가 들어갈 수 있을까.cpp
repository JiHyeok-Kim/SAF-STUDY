#include <iostream>
#include <cstring>
using namespace std;

int N, K;
int map[15][15];
int directY[4] = { 1,-1,0,0 };
int directX[4] = { 0,0,-1,1 };
int ans;

void isValid(int y, int x)
{
	int direct[2] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			int dy = y + directY[i] * j;
			int dx = x + directX[i] * j;
			if (dy < 0 || dx < 0 || dy >= N || dx >= N) break;
			if (map[dy][dx] == 0) break;
			direct[i / 2]++;
		}
	}

	if (direct[0] + 1 == K) ans++;
	if (direct[1] + 1 == K) ans++;

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin.tie(0);
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		ans = 0;
		memset(map, 0, sizeof(map));

		cin >> N >> K;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cin >> map[y][x];
			}
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (map[y][x] == 0) continue;
				isValid(y, x);
			}
		}

		ans /= K;
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}