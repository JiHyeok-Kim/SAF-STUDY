#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
int parent[10001];
int ret;

typedef struct {
	int cur, next;
	int cost;
}NODE;
vector <NODE> v;

bool compare(NODE t, NODE v) {
	return t.cost < v.cost;
}

int Find(int tar) {
	if (parent[tar] == 0) return tar;
	int ret = Find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
}

int main()
{
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < E; ++i) {
		int cur = v[i].cur;
		int next = v[i].next;
		if (Find(cur) == Find(next)) continue;
		Union(cur, next);
		ret += v[i].cost;
	}
	
	cout << ret;
	return 0;
}