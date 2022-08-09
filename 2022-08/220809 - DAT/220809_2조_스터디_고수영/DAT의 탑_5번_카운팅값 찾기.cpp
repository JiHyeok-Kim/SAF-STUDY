#include <iostream>

using namespace std;

int main()
{
	int arr[3][5] = { {1,3,3,5,1},{3,6,2,4,2},{1,9,2,6,5} };
	int check[10] = { 0 };
	int n;
	cin >> n;

	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 5; b++)
		{
			check[arr[a][b]]++;
		}
	}

	for (int a = 0; a < 10; a++)
	{
		if (check[a] == n)
		{
			cout << a << " ";
		}
	}
	
}