#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char arr[8];
	int arr1[150] = { 0 };
	cin >> arr;

	for (int i = 0; i < strlen(arr); i++)
	{
		arr1[arr[i]]++;
	}

	int max = -1;
	for (int i = 0; i < 150; i++)
	{
		if (arr1[i] > max)
		{
			max = arr1[i];
		}
	}
	for (int i = 0; i < 150; i++)
	{
		if (arr1[i] == max)
		{
			cout << (char)i;
			break;
		}
	}
	return 0;
}