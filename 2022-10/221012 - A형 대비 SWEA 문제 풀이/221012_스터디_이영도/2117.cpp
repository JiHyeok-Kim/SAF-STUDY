// 홈 방범 서비스
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int map[21][21], used[21][21], N, M, Max;
int dy[] = { 0, 0, -1 ,1 };
int dx[] = { -1, 1, 0, 0 };
typedef struct {
	int y, x, len;
}str;
queue<str> que;

void bfs(str tmp, int lim) {
	int cnt = 0;

	int pay = lim * lim + (lim - 1) * (lim - 1); // pay

	if (map[tmp.y][tmp.x] == 1) { cnt++; } // start home check
	used[tmp.y][tmp.x] = 1; // start used check
	que.push(tmp); // queue start

	while (!que.empty()) { 
		str now = que.front();
		que.pop();

		for (int dir = 0; dir < 4; dir++) { // 4 direction
			int ny = now.y + dy[dir];
			int nx = now.x + dx[dir];
			int nlen = now.len + 1;

			// out of map, used, limit
			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
			if (used[ny][nx] != 0) continue;
			if (nlen > lim) continue;

			if (map[ny][nx] == 1) cnt++; // home check
			used[ny][nx] = nlen; // used update
			que.push({ ny, nx, nlen }); // queue update
		}
	}

	for (int i = 0; i < 21; i++) { // used initialization
		memset(used[i], 0, sizeof(used[i]));
	}

	// final cost
	int cost = (cnt * M) - pay;

	if (cost >= 0) { // Max update
		if (cnt > Max) {
			Max = cnt;
		}
	}

}

void init() { // initialization function
	N = 0;
	M = 0;
	Max = -21e8;
//	while (!que.empty()) {
//		que.pop();
//	};
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		cin >> N >> M;

		for (int y = 0; y < N; y++) { // map initialization
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
			}
		}

		for (int k = 1; k <= N + 1; k++) {  // limit
			int p = 0;
			if ((k % 2) == 1) p = k / 2;
			for (int y = p; y < N; y++) {  // search
				for (int x = p; x < N; x++) {
					str tmp = { y, x, 1 };
					bfs(tmp, k);
				}
			}
		}
		
		cout << "#" << tc + 1 << " " << Max << endl;
	}

	return 0;
}