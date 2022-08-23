#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int arr[1001];


void init()
{
	for (int i = 0; i < 1001; i++)
	{
		arr[i] = -1;
	}
}
int findBoss(int tar)
{
	if (arr[tar] == -1) return tar;
	return findBoss(arr[tar]);
}

void unionGroup(int a, int b)
{
	if (findBoss(a) == findBoss(b)) return;
	arr[findBoss(b)] = findBoss(a);
}


int main()
{
	init();
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < Q; i++)
	{
		int K, A, B;
		cin >> K >> A >> B;

		if (K == 0)
		{
			if (findBoss(A) == findBoss(B))
			{
				cout << "YES" << '\n';
			}
			else if (findBoss(A) != findBoss(B))
			{
				cout << "NO" << '\n';
			}
		}
		else if (K == 1)
		{
			unionGroup(A, B);
		}
	}
}