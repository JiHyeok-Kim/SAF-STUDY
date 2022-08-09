#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int arr[4][4] = { 0 };
int main()
{

	char a;
	int x;
	for (int k = 0; k < 3; k++)
	{


		cin >> a >> x;

		if (a == 'G')
		{
			for (int j = 0; j < 4; j++)
			{
				arr[x][j] = 1;
			}
		}
		else if (a == 'S')
		{
			for (int i = 0; i < 4; i++)
			{
				arr[i][x] = 1;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << " ";

		}
		cout << '\n';
	}
	return 0;
}