#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int flag = 0;
int used[10] = { 0 };
int map[10][10];
void init()
{

	for (int i = 1; i <= 9; i++)
	{
		used[i] = 0;
	}
}
int  w_com(int y)
{
	for (int i = 0; i < 9; i++)
	{
		used[map[y][i]]++;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();
	return 1;
	
}


int h_com(int x)
{
	for (int i = 0; i < 9; i++)
	{
		used[map[i][x]]++;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();
	return 1;
}

int sum_com()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			used[map[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			used[map[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 6; j < 9; j++)
		{
			used[map[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();

	//2번째 줄
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			used[map[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();
	for (int i = 3; i < 6; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			used[map[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();
	for (int i = 3; i < 6; i++)
	{
		for (int j = 6; j < 9; j++)
		{
			used[map[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();



	//3번째 줄
	for (int i = 6; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			used[map[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();
	for (int i = 6; i < 9; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			used[map[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();
	for (int i = 6; i < 9; i++)
	{
		for (int j = 6; j < 9; j++)
		{
			used[map[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (used[i] != 1) return 0;
	}
	init();





	return 1;



}

int main()
{
	int testcase;

	cin >> testcase;
	for (int tc = 0; tc < testcase; tc++)
	{
		
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> map[i][j];
			}
		}
		init();
		// 가로 검증
		for (int i = 0; i < 9; i++)
		{
			if (w_com(i) == 0)
			{
				flag++;
				break;

			}
		}
		//세로 검증
		for (int i = 0; i < 9; i++)
		{
			if (h_com(i) == 0)
			{
				flag++;
				break;
			}
		}
		//정사각형 검증
		if (sum_com() == 0)
		{
			flag++;
		}
		

		if (flag != 0)
		{
			cout << '#' << tc + 1 << ' ' << 0 << '\n';
			flag = 0;
		}
		else if (flag == 0)
		{
			cout << '#' << tc + 1 << ' ' << 1 << '\n';
			flag = 0;
		}

	}
	


}