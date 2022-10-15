#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	int life;
	int birth_time;
	int bunsik_time;
	int dead_time;
};
int T, N, M, K;
Node map[400][400];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };

void bunsik(int timee) {
	for (int y = 0; y < 400; y++) {
		for (int x = 0; x < 400; x++) {
			if (map[y][x].life == 0) continue;
			if (map[y][x].bunsik_time != timee) continue;
			for (int i = 0; i < 4; i++) {
				int ny = y + drY[i];
				int nx = x + drX[i];
				if (ny < 0 || nx < 0 || ny >= 400 || nx >= 400) continue;
				if (map[ny][nx].life >= map[y][x].life) continue;
				if ((map[ny][nx].life != 0) && (map[ny][nx].birth_time < timee)) continue;
				map[ny][nx].life = map[y][x].life;
				map[ny][nx].birth_time = timee;
				map[ny][nx].bunsik_time = map[y][x].life + 1 + timee;
				map[ny][nx].dead_time = (2 * map[y][x].life) + timee;
			}
		}
	}
}
int getCnt(int timee) {
	int cnt = 0;
	for (int y = 0; y < 400; y++) {
		for (int x = 0; x < 400; x++) {
			if (map[y][x].life == 0) continue;
			if (map[y][x].dead_time <= timee) continue;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(map, 0, sizeof(map));
		cin >> N >> M >> K;
		int N1 = N / 2;
		int M1 = M / 2;
		for (int y = 200 - N1; y < (200 - N1 + N); y++) {
			for (int x = (200 - M1); x < (200 - M1 + M); x++) {
				cin >> map[y][x].life;
				map[y][x].birth_time = 0;
				map[y][x].bunsik_time = map[y][x].life + 1;
				map[y][x].dead_time = 2 * map[y][x].life;
			}
		}
		for (int i = 1; i <= K; i++) {
			bunsik(i);
		}
		int ans = getCnt(K);
		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}