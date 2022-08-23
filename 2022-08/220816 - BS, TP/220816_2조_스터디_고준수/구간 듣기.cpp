#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[3][4] = {3,2,5,3,7,6,1,6,4,9,2,7 };

int rec(int y,int x,int n)
{
	if (x - n < 0)
	{
		x += 2;
	}
	return arr[y][x - n];
}
int main()
{
	for (int i = 0; i < 4; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < 3; j++)
		{
			cout <<rec(i, j, x);
		}

		cout << '\n';
	}
	
	
	

	
}