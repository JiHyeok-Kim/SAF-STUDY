#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v(100001);
queue<int> q;
int used[100001] = { 0 };
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	int start;
	cin >> start;
	used[start] = 1;
	q.push(start);
	int cnt = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (used[next] == 1) continue;
			used[next] = 1;
			cnt++;
			q.push(next);
		}
	}
	cout << cnt;

	return 0;
}