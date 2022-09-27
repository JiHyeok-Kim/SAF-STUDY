#include <iostream>
#include <string>
#include <queue>;
using namespace std;
struct Node {
	int y, x;
	int lev;
};
int N;
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
queue<Node> q;

void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		string map[50];
		for (int i = 0; i < N; i++) cin >> map[i];
		int used[50][50] = { 0 };
		q.push({ N / 2,N / 2,0 });
		used[N / 2][N / 2] = 1;
		int result = map[N / 2][N / 2] - '0';
		while (!q.empty()) {
			Node now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = now.y + drY[i];
				int nx = now.x + drX[i];
				if (now.lev + 1 >= (N / 2) + 1) continue;
				//if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (used[ny][nx] == 1)continue;
				used[ny][nx] = 1;
				result += map[ny][nx] - '0';
				q.push({ ny,nx,now.lev + 1 });
			}
		}
		cout << "#" << t << " " << result << "\n";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
}