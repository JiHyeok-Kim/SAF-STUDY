#include <iostream>
using namespace std;

int map[5][5] = {
	3, 3, 5, 3, 1,
	2, 2, 4, 2, 6,
	4, 9, 2, 3, 4,
	1, 1, 1, 1, 1,
	3, 3, 5, 9, 2,
};

int sum(int y, int x)
{
	int direct[4][2] = {
		-1,-1,
		-1,1,
		1,-1,
		1,1,
	};
	int dy, dx, t;

	int sum = 0;
	for (t = 0; t < 4; t++)
	{
		dy = y + direct[t][0];
		dx = x + direct[t][1];
		if (dy >= 0 && dy < 5 && dx >= 0 && dx < 5)
		{
			sum += map[dy][dx];
		}
	}
	return sum;
}

int main()
{
	int x, y;
	int max = -999;
	int maxY, maxX;

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			int ret = sum(y, x);

			if (ret > max)
			{
				max = ret;
				maxY = y;
				maxX = x;
			}
		}
	}

	cout << maxY << " " << maxX;

	return 0;
}