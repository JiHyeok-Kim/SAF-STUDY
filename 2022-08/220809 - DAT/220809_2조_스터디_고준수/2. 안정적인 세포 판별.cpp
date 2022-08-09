#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[5][4];
int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> arr[i][j];

		}
	}

	for (int i = 0; i < 5; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 1)
			{
				cnt++;
			}
		}
		if (cnt >= 2)
		{
			cout << "안정된 상태";
			return 0;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 5; j++)
		{
			if (arr[j][i] == 1)
			{
				cnt++;
			}
		}
		if (cnt >= 2)
		{
			cout << "안정된 상태";
			return 0;
		}
	}
	cout << "불안정한 상태";


	return 0;
}