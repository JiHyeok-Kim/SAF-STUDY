#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <valarray>
#include <string>
using namespace std;



int cy, cx;
int mask[2][2];
int arr[3][3] = { 3,5,1,3,8,1,1,1,5 };
int solved(int ty, int tx)
{
	int sum = 0;
	for (int y = ty; y < 2; ++y)
	{
		for (int x = tx; x < 2; ++x)
		{
			if (mask[y - ty][x - tx] == 1)
			{
				sum += arr[y][x];
			}
		}
	}

	return sum;
}

int max_num = -1;
int idy = 0;
int idx = 0;

int main()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> mask[i][j];
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int comp = solved(i, j);
			if (comp > max_num)
			{
				max_num = comp;
				idy = i;
				idx = j;

			}
		}

	}
	cout << "(" << idy << "," << idx << ")";
}