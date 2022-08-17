#include <iostream>
#include <queue>
using namespace std;

int N, M;
priority_queue<int, vector<int>, greater<int> > pq1;
priority_queue<int, vector<int>, greater<int> > pq6;
priority_queue<int, vector<int>, greater<int>> cost;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		pq6.push(a);
		pq1.push(b);
	}
	int pq6Cost = pq6.top();
	int pq1Cost = pq1.top();
	cost.push((N / 6) * pq6Cost + (N % 6) * pq1Cost);
	cost.push(((N / 6) + 1) * pq6Cost);
	cost.push(N * pq1Cost);
	int ans = cost.top();
	cout << ans;
	return 0;
}