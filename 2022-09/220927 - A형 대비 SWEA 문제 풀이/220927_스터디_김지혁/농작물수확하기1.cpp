#include <iostream>
#include <cstring>
using namespace std;

int N;
int map[50][50];

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio;

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		memset(map, 0, sizeof(map));
		for (int y = 0; y < N; y++)
		{
			string str;
			int idx = -1;
			cin >> str;
			for (int x = 0; x < N; x++)
			{
				idx++;
				map[y][x] = str[idx] - '0';
			}
		}
		int n = (N - 1) / 2;
		int ans = 0;
		int i = -1;
		for (int y = 0; y < N; y++)
		{
			i++;
			if (y > n) i -= 2;
			for (int x = n - i; x <= n + i; x++)
			{
				ans += map[y][x];
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}
