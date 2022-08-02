#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int map[10][10];
int used[10][10];

struct Zombie {
	int y;
	int x;
	int t;
};
queue<Zombie> q;

int main() {
	int cnt = 0;
	int answer = 0;
	int w, h;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < w; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	int y, x;
	cin >> x >> y;
	q.push({ y - 1,x - 1,3 });

	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };

	while (!q.empty()) {
		Zombie now = q.front();
		q.pop();

		map[now.y][now.x] = 0;

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
				if (map[ny][nx] == 1) {
					if (used[ny][nx] == 1) continue;
					used[ny][nx] = 1;
					q.push({ ny,nx,now.t + 1 });
				}
			}
		}
		answer = now.t;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1) cnt++;
		}
	}

	cout << answer << '\n' << cnt;

	return 0;
}