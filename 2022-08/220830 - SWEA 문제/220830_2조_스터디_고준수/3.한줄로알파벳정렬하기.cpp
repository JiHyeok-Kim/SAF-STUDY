#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char arr1[5][3] = { {'A','B','C'},{'A','G','H'},{'H','I','J'},{'K','A','B'} ,{'A','B','C' } };

	int arr2[25] = { 0 };


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr2[arr1[i][j] - 65]++;
		}
	}

	for (int i = 0; i < 25; i++)
	{
		if (arr2[i] != 0)
		{
			for (int j = 0; j < arr2[i]; j++)
			{
				cout << char(65 + i);
			}

		}
	}
	return 0;
}