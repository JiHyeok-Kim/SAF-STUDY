#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



char map[3][4] = { 'A','B','G','K','T','T','A','B','A','C','C','D' };
char pat[2][2];

int main()
{

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> pat[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[i][j] == pat[0][0] && map[i][j + 1] == pat[0][1] && map[i + 1][j] == pat[1][0] && map[i + 1][j + 1] == pat[1][1])
			{
				cnt++;
			}
		}

	}

	if (cnt >= 1)
	{
		cout << "발견(" << cnt << "개)";
	}
	else if (cnt == 0)
	{
		cout << "미발견";
	}



	return 0;
}