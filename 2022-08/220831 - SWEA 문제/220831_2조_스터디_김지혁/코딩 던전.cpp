#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int Map[11][11] = { 0 };
int dat[11] = { 0 };
queue<int> q;
vector<int> v;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int from, to, gold;
		cin >> from >> to >> gold;
		Map[from][to] = gold;
	}
	int flag = 0;
	q.push(0);
	int sum = 0;
	dat[0] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next = 1; next <= 10; next++) {
			if (Map[now][next] == 0)continue;
			if ((dat[now] + Map[now][next]) > K) continue;
			q.push(next);
			dat[next] = Map[now][next];
			v.push_back(next);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}