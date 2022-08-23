#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

struct Node {
	int x;
	int y;
};

int arr[1000][1000] = { 0 };
int parent[1000];
int N;
int flag = 0;

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
		flag = 1;
		return;
	}

	
	parent[pB] = pA;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			//if(arr[i][j] ==1) Union(i, j);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			
			if(arr[i][j] ==1) Union(i, j);
		}
		if (flag == 1)break;
	}
	if (flag == 1)cout<<"WARNING";
	else cout << "STABLE";
}