#include <iostream>
using namespace std;

int line[100001];
int G;
int P;
int ans;

int findBoss(int tar)
{
	if (line[tar] == tar) return tar;
	int ret = findBoss(line[tar]);
	line[tar] = ret;
	return ret;
}

void unionGroup(int a, int b)
{
	int t1 = findBoss(a);
	int t2 = findBoss(b);
	if (t1 == t2) return;

	line[t2] = t1;

	return;
}

int main()
{
	//freopen_s(new FILE*, "test.txt", "r", stdin);
	cin >> G;
	cin >> P;
	for (int i = 0; i <= G; i++)
	{
		line[i] = i;
	}

	for (int i = 0; i < P; i++)
	{
		int n;
		cin >> n;
		while (1)
		{
			int u = findBoss(n);
			int h = 0;
			if (n == u) {
				unionGroup(n - 1, n);
				ans++;
				break;
			}
			n--;
			if (findBoss(n) == 0) {
				cout << ans;
				return 0;
			}
		}
	}
	cout << P;

	return 0;
}