#include <iostream>
#include <string>
using namespace std;

int directY[2] = { 1, 0 };
int directX[2] = { 0, 1 };

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (1)
	{
		int T;
		if (!(cin >> T)) break;

		string str[100];
		for (int i = 0; i < 100; i++)
		{
			cin >> str[i];
		}

		int ans = 1;
		int flag = 0;
		for (int y = 0; y < 100; y++)
		{
			for (int x = 0; x < 100; x++)
			{
				for (int i = 0; i < 2; i++)
				{
					for (int j = 1; j <= 50; j++)
					{
						int dy = y + directY[i] * j;
						int dx = x + directX[i] * j;
						int my = y - directY[i] * j;
						int mx = x - directX[i] * j;
						if (dy < 0 || dx < 0 || dy >= 100 || dx >= 100) break;
						if (my < 0 || mx < 0 || my >= 100 || mx >= 100) break;
						if (str[dy][dx] == str[my][mx]) {
							int n = j * 2 + 1;
							if (n > ans) ans = n;
						}
						else break;
					}

					for (int j = 0; j <= 50; j++)
					{
						int dy = y + directY[i] * (j + 1);
						int dx = x + directX[i] * (j + 1);
						int my = y - directY[i] * j;
						int mx = x - directX[i] * j;
						if (dy < 0 || dx < 0 || dy >= 100 || dx >= 100) break;
						if (my < 0 || mx < 0 || my >= 100 || mx >= 100) break;
						if (str[dy][dx] == str[my][mx]) {
							int n = (j + 1) * 2;
							if (n > ans) ans = n;
						}
						else break;
					}
				}
			}
		}

		cout << "#" << T << " " << ans << "\n";
	}

	return 0;
}
