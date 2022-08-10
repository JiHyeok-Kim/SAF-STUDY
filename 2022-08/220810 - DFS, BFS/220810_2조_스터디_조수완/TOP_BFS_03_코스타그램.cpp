#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> alist(100000);
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
		alist[to].push_back(from);
	}
	int startNode;
	cin >> startNode;
	int used[100000] = { 0, };
	int cnt = 0;

	queue<int> q;
	q.push(startNode);
	used[startNode] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i];
			if (used[next] > 0) continue;
			used[next] = 1;
			cnt++;
			q.push(next);
		}
	}
	cout << cnt;
	return 0;
}