#include <iostream>

using namespace std;

int main()
{
	char arr[5][3] = { {'A','B','C'},{'A','G','H'},{'H','I','J'},{'K','A','B'},{'A','B','C'} };
	char eng[100] = {0};
	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			eng[arr[a][b]]++;
		}
	}
	for (int a = 60; a < 100; a++)
	{
		if (eng[a] != 0)
		{
			for (int b = 0; b < eng[a]; b++)
			{
				cout << char(a);
			}
			
		}
	}
	
}