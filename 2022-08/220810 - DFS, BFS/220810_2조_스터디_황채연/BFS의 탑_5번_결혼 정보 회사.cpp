#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
vector <vector<int>> list(101);
bool visited[101];
queue <int> q;

void BFS(int target, int comp) {
	q.push(target);

	while (!q.empty()) {
		int cur = q.front();	q.pop();
		visited[cur] = true;

		if (cur == comp) {
			cout << "YES";
			return;
		}

		for (int i = 0; i < list[cur].size(); ++i) {
			int next = list[cur][i];
			if (visited[next] == true) continue;
			q.push(next);
		}
	}

	cout << "NO";
}

int main()
{
	cin >> N >> T;
	for (int i = 0; i < T; ++i) {
		int one, two;
		cin >> one >> two;
		list[one].push_back(two);
		list[two].push_back(one);
	}
	int target, comp;
	cin >> target >> comp;

	visited[target] = true;
	BFS(target, comp);
	return 0;
}