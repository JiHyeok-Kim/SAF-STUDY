#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Node {
	int from, to, cost;
};
queue<int> q;
vector<Node> v;
int dat[100001] = { 0 };
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v.push_back({ from, to, cost });
	}
	int a = 2;
	q.push(1);
	dat[0] = 0;
	int cnt = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].from == now) {
				int next = v[i].to;
				sum = dat[now] + v[i].cost;
				if (sum > K)continue;
				dat[next] = sum;
				q.push(next);
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}