#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int parent[26];
int gCnt[26];
int Grop[26];
int N;
int cnt;
int people=0;

int Find(int now)
{
	if (parent[now] == now)return now;

	int root = Find(parent[now]);
	return root;
}

void Union(int A, int B)
{
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB)
	{
		return;
	}
	parent[pB] = pA;
	Grop[pA] = 1;
	Grop[pB] = 1;
	gCnt[pA]++;
	gCnt[pB] = 0;
}

int main()
{
	cin >> N;

	for (int i = 0; i < 26; i++)
	{
		parent[i] = i;
		gCnt[i] = 0;
		Grop[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		char a, b;
		cin >> a >> b;
		Union(int(a - 65), int(b - 65));
	}

	for (int i = 0; i < 26; i++)
	{
		if (gCnt[i] != 0)
		{
			cnt++;
		}

		if (Grop[i] != 1)
			people ++;
	}
	int aaa = 1;
	cout << cnt << '\n'<<people;
}