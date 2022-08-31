#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int black[1001][1001];
int map[1001][1001];
int black_cnt = 0;
int h, w;
int a, b;
int cnt = 0;
int civil_cnt = 0;
int DAT[100000001] = { 0 };

void find_black(int y, int x)
{
	if (DAT[map[y][x]] == 1)
	{
		black_cnt++;
	}
	else if (DAT[map[y][x]] == 0)
	{
		civil_cnt++;
	}
}


int main()
{

	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];

		}
	}


	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> black[i][j];
			DAT[black[i][j]] = 1;
		}
	}


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			find_black(i, j);
		}
	}

	cout << black_cnt << '\n' << civil_cnt;





	return 0;
}