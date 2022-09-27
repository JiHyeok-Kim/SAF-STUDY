#include <iostream>
#include <cstring>
using namespace std;

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
		int N;
		cin >> N;
		string map[50];
		for (int y = 0; y < N; y++)
		{
			cin >> map[y];
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
				ans += map[y][x] - '0';
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}
