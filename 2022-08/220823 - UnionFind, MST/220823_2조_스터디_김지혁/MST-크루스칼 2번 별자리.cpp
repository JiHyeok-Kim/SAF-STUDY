#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
	double y;
	double x;
};

struct Node1 {
	int y;
	int x;
	double val;
};

vector<Node> vect;
vector<Node1> edge;
int line[100];
int n;

bool cmp(Node1 t, Node1 v)
{
	return t.val < v.val;
}

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
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		line[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		double y, x;
		cin >> y >> x;
		vect.push_back({ y, x });
	}
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (y == x) continue;
			double ret = (vect[y].y - vect[x].y) * (vect[y].y - vect[x].y) + (vect[y].x - vect[x].x) * (vect[y].x - vect[x].x);
			double val = sqrt(ret);
			edge.push_back({ y, x, val });
		}
	}

	sort(edge.begin(), edge.end(), cmp);

	int cnt = 0;
	double ans = 0;
	for (int i = 0; i < (n - 1) * (n - 1); i++)
	{
		if (findBoss(edge[i].y) == findBoss(edge[i].x)) continue;
		unionGroup(edge[i].y, edge[i].x);
		cnt++;
		ans += edge[i].val;
		if (cnt == n - 1) break;
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;

	return 0;
}