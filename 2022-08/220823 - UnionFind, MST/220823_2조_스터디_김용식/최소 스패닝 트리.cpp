#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int from, to, cost;
};

bool compare(Node t, Node v) {
	if(t.cost < v.cost )return true;
	if (t.cost > v.cost)return false;
	
	return false;
}

vector<Node> edge;
int parent[10000];


int Find(int now) {
	if (parent[now] == now)return now;
	return parent[now] = Find(parent[now]);
}


void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	parent[pB] = pA;

}




int main() {
//	freopen_s(new FILE*, "input.txt", "r", stdin);
	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;

	for (int i = 1; i < 10000; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < cntEdge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge.push_back({ from, to, cost });
	}
	sort(edge.begin(), edge.end(), compare);
	
	int sum = 0;
	for (int i = 0; i < edge.size(); i++) {
		int from = edge[i].from;
		int to = edge[i].to;
		if (Find(from) == Find(to))continue;
		Union(from, to);
		sum += edge[i].cost;
	

	}
	cout << sum;


	return 0;
}