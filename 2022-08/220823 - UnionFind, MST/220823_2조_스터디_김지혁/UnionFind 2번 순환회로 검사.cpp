#include <iostream>
using namespace std;

int line[100];
int N;
int table[1000][1000];

int findBoss(int tar)
{
	if (line[tar] == 0) return tar;

	int ret = findBoss(line[tar]);
	line[tar] = ret;

	return ret;
}

int unionGroup(int a, int b)
{
	int t1 = findBoss(a);
	int t2 = findBoss(b);
	if (t1 == t2) return 0;

	line[t2] = t1;

	return 1;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> table[y][x];
		}
	}

	for (int from = 0; from < N; from++)
	{
		for (int to = 0; to <= from; to++)
		{
			if (table[from][to] == 1)
			{
				if (unionGroup(from, to) == 0)
				{
					cout << "WARNING";
					return 0;
				}
			}
		}
	}
	cout << "STABLE";

	return 0;
}