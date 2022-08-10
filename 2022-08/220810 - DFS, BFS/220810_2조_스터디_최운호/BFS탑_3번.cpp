#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> v(100002);
int used[100002];
int cnt;

int main() {
	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;


	for (int i = 0; i < cntEdge; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	int node;
	cin >> node;

	queue<int> q;
	q.push(node);
	used[node] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (used[next] == 1) continue;
			used[next] = 1;
			q.push(next);
		}
	}
	for (int i = 1; i <= cntNode; i++) {
		if (used[i] == 0 || i == node) continue;
		cnt++;
	}

	cout << cnt;

	return 0;
}