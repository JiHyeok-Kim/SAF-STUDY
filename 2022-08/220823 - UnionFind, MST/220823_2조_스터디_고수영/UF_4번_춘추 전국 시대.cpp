#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int parent[25];
int alive[25];
int gCnt[25];
int N, T;
int flag = 0;
int cnt = 0;

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
	if (pA == pB)return;
	if (alive[pB] == -1 || alive[pA] == -1) return;

	parent[pB] = pA;
	gCnt[pA] += gCnt[pB];
	gCnt[pB] = 0;
}

int main()
{
	cin >> N;
	int result;
	for (int i = 0; i < N; i++)
	{
		cin >> gCnt[i];
		parent[i] = i;
		alive[i] = 1;
	}

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string a;
		char b;
		char c;
		cin >> a >> b >> c;
		if (a == "alliance")
			Union(int(b - 65), int(c - 65));
		else
		{
			int A_team = gCnt[Find(int(b - 65))];
			int B_team = gCnt[Find(int(c - 65))];

			int X = Find(int(b - 65));
			int Y = Find(int(c - 65));

			if (A_team > B_team)
			{
				for (int i = 0; i < N; i++)
				{
					
					if (parent[i] == Y) alive[i] = -1;
				}

				for (int i = 0; i < N; i++)
				{
					if (alive[i] == 1) cnt++;
				}
				result = cnt;
				cnt = 0;

			}
			if (A_team < B_team)
			{
				for (int i = 0; i < N; i++)
				{
					
					if (parent[i] == X) alive[i] = -1;
				}

				for (int i = 0; i < N; i++)
				{
					if (alive[i] == 1) cnt++;
				}
				result = cnt;
				cnt = 0;

			}
			if (A_team == B_team)
			{
				for (int i = 0; i < N; i++)
				{
					if (parent[i] == X) alive[i] = -1;
					if (parent[i] == Y) alive[i] = -1;
				}

				for (int i = 0; i < N; i++)
				{
					if (alive[i] == 1) cnt++;
				}
				result = cnt;
				cnt = 0;

			}
		}

	}
	cout << result;
}