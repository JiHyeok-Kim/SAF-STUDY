#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int from, to;
	int cost;
};
vector<Node> alist;
int V, E;
int parent[11000];

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return;
	parent[pB] = pA;
}

bool cmp(Node t, Node v) {
	return t.cost < v.cost;
}

int main() {
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		alist.push_back({ from,to,cost });
	}
	sort(alist.begin(), alist.end(), cmp);
	int cnt = 0, result = 0;
	for (int i = 0; i < E; i++) {
		int from = alist[i].from;
		int to = alist[i].to;
		if (Find(from) == Find(to)) continue;
		Union(from, to);
		cnt++;
		result += alist[i].cost;
		if (cnt == V) break;
	}
	cout << result;
	return 0;
}