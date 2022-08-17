#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int num[10] = { 0 };
};

int arr[501][501] = { 0 };
Node ret[501][501];

int main()
{
	int N, Q;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> Q;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int t = 0; t < 10; t++)
			{
				ret[i][j].num[t] = ret[i - 1][j].num[t] + ret[i][j - 1].num[t] - ret[i - 1][j - 1].num[t];
				if (arr[i][j] == t)ret[i][j].num[t]++;
			}
		}
	}


	for (int i = 0; i < Q; i++)
	{
		int A, B, C, D;
		cin >> A >> B >> C >> D;
		Node tmp;
		tmp = ret[C][D];
		for (int t = 0; t < 10; t++)
		{
			tmp.num[t] = ret[C][D].num[t] - ret[C][B - 1].num[t] - ret[A - 1][D].num[t] + ret[A - 1][B - 1].num[t];

		}

		int maxi = 0;
		int result = -1;
		for (int c = 0; c < 10; c++)
		{
			if (tmp.num[c] > maxi)
			{
				maxi = tmp.num[c];
				result = c;
			}
		}
		cout << result << '\n';
	}

}