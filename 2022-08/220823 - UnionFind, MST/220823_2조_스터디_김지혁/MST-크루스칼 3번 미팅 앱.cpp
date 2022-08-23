#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
	int y;
	int x;
	int dist;
};

int N, M;
vector<Node> univ;
char univSex[1001];
int parent[1001];
int cnt;
int ans;

bool cmp(Node t, Node v)
{
	return t.dist < v.dist;
}

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

void isLove()
{
	for (int i = 0; i < M; i++)
	{
		if (univSex[univ[i].y] == univSex[univ[i].x]) continue;
		if (findBoss(univ[i].y) == findBoss(univ[i].x)) continue;
		unionGroup(univ[i].y, univ[i].x);
		cnt++;
		ans += univ[i].dist;
		if (cnt == N - 1) break;
	}

	return;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> univSex[i];
		parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		univ.push_back({ u,v,d });
	}

	sort(univ.begin(), univ.end(), cmp);

	isLove();

	if (cnt < N - 1) {
		cout << -1; return 0;
	}
	cout << ans;

	return 0;
}