#include <iostream>
using namespace std;

int image[4][4];

int rectSum(int dy, int dx)
{
	int x, y;
	int sum = 0;
	for (y = 0; y < 2; y++)
	{
		for (x = 0; x < 3; x++)
		{
			sum += image[dy + y][dx + x];
		}
	}
	return sum;
}

int main()
{
	int x, y;
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			cin >> image[y][x];
		}
	}

	int max = -999;
	int maxY, maxX;
	for (y = 0; y <= 2; y++)
	{
		for (x = 0; x <= 1; x++)
		{
			int ret = rectSum(y, x);
			if (ret > max)
			{
				max = ret;
				maxY = y;
				maxX = x;
			}
		}
	}

	cout << "(" << maxY << "," << maxX << ")";

	return 0;
}