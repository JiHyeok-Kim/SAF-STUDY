#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> v(101);
int used[101];

int main() {
	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;

	for (int i = 0; i < cntEdge; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	int a, b;
	cin >> a >> b;

	queue<int> q;
	q.push(a);
	used[a] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == b) {
			cout << "YES";
			return 0;
		}

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (used[next] == 1) continue;
			used[next] = 1;
			q.push(next);
		}
	}

	cout << "NO";

	return 0;
}