#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N, ans, start, last;
int map[110][110];
int used[110][110];
int ditY[] = { -1,1,0,0 };
int ditX[] = { 0,0,-1,1 };

struct Node {
	int y, x;
};
queue<Node> q;

void input() {
	cin >> N;
	start = 101;
	last = -1;
	ans = 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			start = min(start, map[y][x]);
			last = max(last, map[y][x]);
		}
	}
}
bool isOut(int ny, int nx) {
	return ny < 0 || nx < 0 || ny >= N || nx >= N;
}

int solve() {

	for (int day = start; day < last; day++) {
		memset(used, 0, sizeof(used));
		int cheeseCnt = 0;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (used[y][x] == 1) continue;
				if (map[y][x] > day) {
					q.push({ y,x });

					while (!q.empty()) {
						Node now = q.front();
						q.pop();
						used[now.y][now.x] = 1;

						for (int i = 0; i < 4; i++) {
							int ny = now.y + ditY[i];
							int nx = now.x + ditX[i];
							if (isOut(ny, nx)) continue;
							if (used[ny][nx] == 1) continue;
							if (map[ny][nx] <= day) continue;
							used[ny][nx] = 1;
							q.push({ ny,nx });
						}
					}

					cheeseCnt++;

				}
			}
		}

		ans = max(ans, cheeseCnt);
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		memset(map, 0, sizeof(map));
		input();
		cout << "#" << tc << " " << solve() << "\n";
	}
	return 0;
}