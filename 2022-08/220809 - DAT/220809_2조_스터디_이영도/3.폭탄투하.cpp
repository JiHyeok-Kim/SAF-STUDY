#include <iostream>
using namespace std;

char map[4][5];

void drop(int y, int x)
{
	int direct[8][2] =
	{
		1, 0,
		-1, 0,
		0, 1,
		0, -1,
		-1, -1,
		-1, 1,
		1, -1,
		1, 1,
	};

	int dy, dx, t;

	for (t = 0; t < 8; t++)
	{
		dy = y + direct[t][0];
		dx = x + direct[t][1];
		if (dy >= 0 && dy < 4 && dx >= 0 && dx < 5)
		{
			map[dy][dx] = '#';
		}
	}
}

int main()
{
	int x, y;

	//'_'·Î ²Ë Ã¤¿ì±â
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 5; x++)
		{
			map[y][x] = '_';
		}
	}

	//ÆøÅº ÅõÇÏ
	cin >> y >> x;
	drop(y, x);

	cin >> y >> x;
	drop(y, x);

	//Ãâ·Â
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 5; x++)
		{
			cout << map[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}