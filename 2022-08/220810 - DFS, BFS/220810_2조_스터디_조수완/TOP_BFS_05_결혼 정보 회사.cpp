#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	vector<vector<int>> alist(100);
	int N, T;
	cin >> N >> T;
	for (int i = 0; i < T; i++) {
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
		alist[to].push_back(from);
	}
	int used[100] = { 0, };
	queue<int> q;
	int start;
	cin >> start;
	q.push(start);
	used[start] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i];
			if (used[next] == 1) continue;
			used[next] = 1;
			q.push(next);
		}
	}
	int target;
	cin >> target;
	if (used[target]) cout << "YES";
	else cout << "NO";

	return 0;
}