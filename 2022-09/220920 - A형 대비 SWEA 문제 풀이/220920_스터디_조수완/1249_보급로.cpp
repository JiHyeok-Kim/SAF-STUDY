#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Node {
	int y, x;
	int cost;
};
string map[110];
int N, result, memo[110][110];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
bool operator< (Node v, Node t) {
	return t.cost < v.cost;
}
priority_queue<Node> q;
void input() {
	cin >> N;
	for (int y = 0; y < N; y++) cin >> map[y];
}
void init() {
	while (!q.empty()) q.pop();
	result = 21e8;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) memo[y][x] = 21e8;
}
void sol() {
	q.push({ 0,0,0 });
	memo[0][0] = 0;
	while (!q.empty()) {
		Node now = q.top();
		q.pop();

		if (now.cost < memo[now.y][now.x]) continue;
		if (now.y == N - 1 && now.x == N - 1) break;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			int nextCost = now.cost + (map[ny][nx]-'0');
			if (memo[ny][nx] > nextCost) {
				memo[ny][nx] = nextCost;
				q.push({ ny,nx,nextCost });
			}
		}
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		init();
		sol();
		cout << "#" << t << " " << memo[N-1][N-1] << "\n";
	}
	return 0;
}