#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node {
	float y, x;
	int idx;
};
struct Edge {
	Node from, to;
	float dist;
};
int n;
Node node[110];
Edge edge[9000];
int parent[110];

bool cmp(Edge t, Edge v) {
	return t.dist < v.dist;
}

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

int Union(Node A, Node B) {
	int pA = Find(A.idx);
	int pB = Find(B.idx);
	if (pA == pB) return 0;
	parent[pB] = pA;
	return 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> node[i].y >> node[i].x;
		node[i].idx = i;
		parent[i] = i;
	}
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			float dist = sqrt((((node[i].y - node[j].y) * (node[i].y - node[j].y)) + ((node[i].x - node[j].x) * (node[i].x - node[j].x))));
			edge[idx] = { node[i],node[j],dist };
			idx++;
		}
	}
	sort(edge, edge + idx, cmp);
	float result = 0;
	for (int i = 0; i < idx; i++) {
		if (Union(edge[i].from, edge[i].to)) {
			result += edge[i].dist;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << result;
	return 0;
}