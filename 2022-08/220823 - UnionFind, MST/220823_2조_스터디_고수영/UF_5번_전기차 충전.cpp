#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int parent[100010];
int used[100010];
int G,P;
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
	parent[pB] = pA;
}

int main()
{
	cin >> G >> P;
	for (int i = 1; i <= G; i++) parent[i] = i;
	for (int i = 0; i < P; i++)
	{
		int x;
		cin >> x;

		int ret = Find(x);
		if (parent[ret]== 0)break;
		
		Union(ret - 1, ret);
		
		cnt++;

	}
	cout << cnt;
}