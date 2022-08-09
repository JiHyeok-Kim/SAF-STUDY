#include<iostream>
using namespace std;

int map[3][3] =
{
	3, 5, 4,
	1, 1, 2,
	1, 3, 9,
};

int main()
{
	int x, y;
	int direct[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };
	int dx, dy, t;

	cin >> y >> x;

	int sum = 0;
	for (t = 0; t < 4; t++)
	{
		dy = y + direct[t][0];
		dx = x + direct[t][1];
		if (dx >= 0 && dx < 3 && dy >= 0 && dy < 3)
		{
			sum += map[dy][dx];
		}
	}

	cout << sum;

	return 0;
}

