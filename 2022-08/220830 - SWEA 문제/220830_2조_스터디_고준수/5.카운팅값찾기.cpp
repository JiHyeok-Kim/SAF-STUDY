#include <iostream>

using namespace std;

int main()
{
	int arr[3][5] = { {1,3,3,5,1},{3,6,2,4,2},{1,9,2,6,5} };

	int arr1[10] = { 0 };

	int num;
	cin >> num;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr1[arr[i][j]]++;
		}
	}

	for (int i = 1; i < 10; i++)
	{
		if (arr1[i] == num)
		{
			cout << i << " ";
		}
	}


	return 0;
}