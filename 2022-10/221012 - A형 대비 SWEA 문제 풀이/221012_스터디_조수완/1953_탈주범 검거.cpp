#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
	int y, x;
	int sec;
};
int N, M, map[55][55], used[55][55];
int R, C, L;
queue<Node> q;
vector<int> dirY[8] = { {}, {-1,1,0,0},{-1,1},{0,0},{-1,0},{1,0},{1,0},{-1,0} };
vector<int> dirX[8] = { {}, {0,0,-1,1},{0,0},{-1,1},{0,1},{0,1},{0,-1},{0,-1} };
vector<int> dirIn[8] = { {}, {2,0,1,3},{2,0},{1,3},{2,3},{0,3},{0,1},{2,1} };
vector<int> dirOut[8] = { {}, {0,2,3,1},{0,2},{3,1},{0,1},{2,1},{2,3},{0,3} };

void init() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			used[y][x] = 0;
			map[y][x] = 0;
		}
	}
}

int isDir(int nowDir, int next) {
	for (int i = 0; i < dirIn[next].size(); i++) {
		if (nowDir == dirIn[next][i]) return 1;
	}
	return 0;
}

int sol() {
	int cnt = 1;
	q.push({ R,C,0 });
	used[R][C] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < dirY[map[now.y][now.x]].size(); i++) {
			int ny = now.y + dirY[map[now.y][now.x]][i];
			int nx = now.x + dirX[map[now.y][now.x]][i];
			int nsec = now.sec + 1;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (nsec == L) continue;
			if (map[ny][nx] == 0) continue;
			if (!isDir(dirOut[map[now.y][now.x]][i], map[ny][nx])) continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;
			q.push({ ny,nx,nsec });
			cnt++;
		}
	}
	return cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> R >> C >> L;
		init();
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> map[y][x];
			}
		}
		int ans = sol();
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}