#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[4];
int arr1[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
int result[4][4] = { 0 };
int main()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}

	int cnt = 1;
	for (int k = 0; k < 4; k++)
	{


		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[k] == arr1[i][j])
				{
					result[i][j] = cnt;
					cnt++;

				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << '\n';

	}
	return 0;
}