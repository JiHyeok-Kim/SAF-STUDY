#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, num;
vector<vector<int>> list(100001);
bool visited[100001];
queue <int> q;
int ret;

void BFS() {

	while (!q.empty()) {
		int cur = q.front();	q.pop();

		for (int i = 0; i < list[cur].size(); ++i) {
			int next = list[cur][i];
			if (visited[next] == true) continue;
			visited[next] = true;
			q.push(next);
			ret++;
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int src, dest;
		cin >> src >> dest;
		list[src].push_back(dest);
		list[dest].push_back(src);
	}
	cin >> num;

	q.push(num);
	visited[num] = true;
	BFS();
	cout << ret;
	return 0;
}