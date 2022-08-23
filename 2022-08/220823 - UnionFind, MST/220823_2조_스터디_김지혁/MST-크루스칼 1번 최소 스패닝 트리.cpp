#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int a, b;
	int val;
};

vector<Node> vect;
int line[10000];

bool cmp(Node t, Node v)
{
	return t.val < v.val;
}

int findBoss(int tar)
{
	if (line[tar] == 0) return tar;

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
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	//freopen_s(new FILE*, "test.txt", "r", stdin);

	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, val;
		cin >> a >> b >> val;
		vect.push_back({ a, b, val });
	}

	sort(vect.begin(), vect.end(), cmp);

	int cnt = 0;
	int result = 0;
	for (int i = 0; i < E; i++)
	{
		if (findBoss(vect[i].a) == findBoss(vect[i].b)) continue;

		unionGroup(vect[i].a, vect[i].b);
		cnt++;
		result += vect[i].val;
		if (cnt == V) break;
	}
	cout << result;

	return 0;
}
