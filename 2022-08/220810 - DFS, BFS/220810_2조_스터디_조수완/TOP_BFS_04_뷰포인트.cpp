#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int to;
	int price;
};

int main() {
	vector<vector<Node>> alist(100000);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int from, to, price;
		cin >> from >> to >> price;
		alist[from].push_back({ to, price });
		alist[to].push_back({ from, price });
	}
	int used[100001] = { 0, };
	int dist[100001] = { 0, };

	queue<int> q;
	q.push(1);
	used[1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i].to;
			if (used[next] > 0) continue;
			used[next] = 1;
			dist[next] = dist[now] + alist[now][i].price;
			q.push(next);
		}
	}
	int cnt = 0;
	for (int i = 2; i < N + 1; i++) {
		if (dist[i] != 0 && dist[i] <= K) cnt++;
	}
	cout << cnt;
	return 0;
}