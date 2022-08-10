#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> v[100002];
int cnt;
int used[100002];

int main() {
	int cntNode, cntEdge, stemina;
	cin >> cntNode >> cntEdge >> stemina;

	for (int i = 0; i < cntEdge; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		v[from].push_back(make_pair(to, val));
		v[to].push_back(make_pair(from, val));
	}

	queue<pair<int, int>> q;

	q.push(make_pair(1, 0));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		if (now.first > 1 && now.second <= stemina) cnt++;

		for (int i = 0; i < v[now.first].size(); i++) {
			pair<int, int> next = v[now.first][i];
			if (used[next.first] == 1) continue;
			used[next.first] = 1;
			q.push(make_pair(next.first, now.second + next.second));
		}
	}

	cout << cnt;

	return 0;
}