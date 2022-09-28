#include <iostream>
#include <cstring>
using namespace std;

int map[9][9];
int flag = 0;
int directY[4] = { -1,1,0,0 };
int directX[4] = { 0,0,-1,1 };

void isValid(int ty, int tx)
{
	int used[10] = { 0 };
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			int dy = ty + y;
			int dx = tx + x;
			used[map[dy][dx]]++;
			if (used[map[dy][dx]] == 2) {
				flag = 1;
				cout << 0 << "\n";
				return;
			}
		}
	}

	return;
}

void isLaneValid(int n)
{
	int usedup[10] = { 0 };
	int usedright[10] = { 0 };
	usedup[map[n][n]]++;
	usedright[map[n][n]]++;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 9; j++) {
			int dy = n + directY[i] * j;
			int dx = n + directX[i] * j;
			if (dy < 0 || dx < 0 || dy >= 9 || dx >= 9) break;
			if (i / 2 == 0) usedup[map[dy][dx]]++;
			if (i / 2 == 1) usedright[map[dy][dx]]++;
			if (usedup[map[dy][dx]] == 2 || usedright[map[dy][dx]] == 2) {
				flag = 1;
				cout << 0 << "\n";
				return;
			}
		}
	}

	return;
}

int main()
{

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		flag = 0;
		memset(map, 0, sizeof(map));

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				cin >> map[y][x];
			}
		}

		cout << "#" << tc << " ";
		for (int y = 0; y < 3; y++)
		{
			int dy = y * 3;
			for (int x = 0; x < 3; x++)
			{
				int dx = x * 3;
				isValid(dy, dx);
				if (flag == 1) break;
			}
			if (flag == 1) break;
		}

		if (flag == 1) continue;
		for (int i = 0; i < 9; i++)
		{
			isLaneValid(i);
			if (flag == 1) break;
		}

		if (flag == 1) continue;
		cout << 1 << "\n";
	}

	return 0;
}