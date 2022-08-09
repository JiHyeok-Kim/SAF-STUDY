#include <iostream>
using namespace std;

int main()
{
	int input[4][2];
	int vect[4][3] = { 0 };
	int a, b;

	for (int i = 0; i < 4; i++)
	{
		cin >> input[i][0] >> input[i][1];
	}

	for (int i = 0; i < 4; i++)
	{
		a = input[i][0];
		b = input[i][1];
		vect[a][b] = 5;
	}

	int x, y;
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 3; x++)
		{
			cout << vect[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}