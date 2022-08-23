#include <iostream>
using namespace std;

int N, Q;
int parent[1001];

int findBoss(int tar)
{
	if (parent[tar] == tar) return tar;

	int ret = findBoss(parent[tar]);
	parent[tar] = ret;

	return ret;
}

void unionGroup(int a, int b)
{
	int t1 = findBoss(a);
	int t2 = findBoss(b);
	if (t1 == t2) return;

	parent[t2] = t1;

	return;
}

void isGroup(int a, int b)
{
	if (findBoss(a) == findBoss(b))
	{
		cout << "YES" << "\n";
	}
	else cout << "NO" << "\n";

	return;
}


int main()
{
	//freopen_s(new FILE*, "test.txt", "r", stdin);
	cin >> N >> Q;
	for (int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < Q; i++)
	{
		int rule, a, b;
		cin >> rule >> a >> b;
		if (rule == 1)
		{
			unionGroup(a, b);
		}
		if (rule == 0)
		{
			isGroup(a, b);
		}
	}

	return 0;
}