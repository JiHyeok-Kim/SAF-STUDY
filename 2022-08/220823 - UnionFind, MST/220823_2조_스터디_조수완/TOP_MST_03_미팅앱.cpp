#include <iostream>
#include <algorithm>
using namespace std;
struct Edge {
	int from, to, cost;
};
Edge edge[11000];
int N, M, parent[1100];
char gender[1100];

bool cmp(Edge t, Edge v) {
	return t.cost < v.cost;
};

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

int Union(int A, int B) {
	if (gender[A] == gender[B]) return 0;
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return 0;
	parent[pB] = pA;
	return 1;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		char temp;
		cin >> temp;
		gender[i] = temp;
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		edge[i] = { u,v,d };
	}
	sort(edge, edge + M, cmp);
	int result = 0, cnt = 0;
	for (int i = 0; i < M; i++) {
		if (Union(edge[i].from, edge[i].to))
		{
			result += edge[i].cost;
			cnt++;
		}
	}
	if (cnt != N - 1) {
		cout << -1;
		return 0;
	}
	cout << result;
	return 0;
}