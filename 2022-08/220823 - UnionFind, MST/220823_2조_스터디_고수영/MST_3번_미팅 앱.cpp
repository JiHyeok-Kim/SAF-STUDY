#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstring>

using namespace std;

int parent[2000];
char gender[2000];
int gCnt[2000];
int N, M;
int sumVal = 0;

struct Node {
	int u;
	int v;
	int d;
};

bool compare(Node t, Node v)
{
	return t.d < v.d;
}

vector<Node>vec;

int Find(int now)
{
	if (parent[now] == now)return now;

	int root = Find(parent[now]);
	parent[now] = root;

	return root;
}

void Union(int A, int B)
{
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB)return;
	parent[pB] = pA;
	gCnt[pA] = 1;
	gCnt[pB] = 0;

	
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> gender[i];
		parent[i] = i;
		gCnt[i] = 1;
	}

	for (int i = 0; i < M; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;

		vec.push_back({ u,v,d });
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++)
	{
		if (Find(vec[i].u) == Find(vec[i].v)) continue;
		if (gender[vec[i].u] == gender[vec[i].v]) continue;

		sumVal += vec[i].d;
		Union(vec[i].u, vec[i].v);
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (gCnt[i] == 1)cnt++;
		if (cnt == 2)break;
	}

	if (cnt > 1)cout << -1;
	else cout << sumVal;

	
}

