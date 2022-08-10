#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
typedef struct {
	int dest;
	int cost;
}NODE;

vector<vector<NODE>> list(100001);
bool visited[100001];
queue <NODE> q;
int ret = -1;

void BFS() {
	q.push({ 1,0 });
	
	while (!q.empty()) {
		NODE cur = q.front();	q.pop();
		visited[cur.dest] = true;
		if (cur.cost > K) continue;

		ret++;
		for (int i = 0; i < list[cur.dest].size(); ++i) {
			NODE next;
			next.dest = list[cur.dest][i].dest;
			next.cost = list[cur.dest][i].cost + cur.cost;
			if (visited[next.dest] == true) continue;
			q.push(next);
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i) {
		int src, dest, hp;
		cin >> src >> dest >> hp;
		list[src].push_back({ dest,hp });
		list[dest].push_back({ src,hp });
	}
	visited[1] = true;
	BFS();
	cout << ret;
	return 0;
}