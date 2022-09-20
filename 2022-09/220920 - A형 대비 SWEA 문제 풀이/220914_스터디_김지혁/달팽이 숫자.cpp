#include <iostream>
using namespace std;

int T;
int directY[4] = { 0, 1, 0, -1 };
int directX[4] = { 1, 0,-1, 0 };

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		cin >> N;
		int map[10][10] = { 0 };

		int dy = 0;
		int dx = 0;
		int num = 1;
		map[0][0] = num;
		for (int i = 0; i < 5; i++)
		{
			i %= 4;
			dy += directY[i];
			dx += directX[i];
			if (num == N * N) {
				break;
			}
			if (dy < 0 || dx < 0 || dy >= N || dx >= N || map[dy][dx] > 0) {
				dy -= directY[i];
				dx -= directX[i];
				continue;
			}
			i--;
			num++;
			map[dy][dx] = num;

		}
		cout << "#" << tc << "\n";
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cout << map[y][x] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}