#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100];
int map[100][100];
int cnt = 0;
void init()
{
	for (int i = 0; i < 100; i++)
	{
		arr[i] = -1;

	}
}
int  FindBoss(int tar)
{
	if (arr[tar] == -1) return tar;
	return FindBoss(arr[tar]);

}


void Union(int a, int b)
{
	if (FindBoss(a) == FindBoss(b))
	{
		cout << "WARNING" << '\n';
		cnt++;
		return;
	}
	arr[b] = FindBoss(a);
}
int main()
{
	init();
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			if (cnt != 0) return 0;
			if (map[i][j] == 1)
			{
				Union(i, j);
			}
		}
	}
	if (cnt == 0)
	{
		cout << "STABLE" << '\n';
	}
}