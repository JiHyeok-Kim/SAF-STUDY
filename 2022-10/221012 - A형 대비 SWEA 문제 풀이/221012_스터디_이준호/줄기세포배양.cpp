#include <iostream>
#include <queue>
using namespace std;
#define lim 500
#define center lim/2

int N, M, K;
int ans;
int range;
int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };

struct Node {
	int life;
	int spr;
};
struct axis {
	int y;
	int x;
	int life;
};
Node map[lim][lim];
queue<axis> q;

void init() {
	ans = 0;
	for (int y = 0; y < lim; y++) {
		for (int x = 0; x < lim; x++) {
			map[y][x].life = 0;
			map[y][x].spr = 0;
		}
	}
	while (!q.empty()) {
		q.pop();
	}
}

void input() {
	cin >> N >> M >> K;
	range = K / 2 + 1;
	for (int y = center; y < center + N; y++) {
		for (int x = center; x < center + M; x++) {
			cin >> map[y][x].life;
			map[y][x].spr = map[y][x].life;
		}
	}
}

void OfftoOn() {

	for (int y = center - range; y <= center + N + range; y++) {
		for (int x = center - range; x <= center + M + range; x++) {
			if (map[y][x].life > 0 && map[y][x].spr > 0) {
				map[y][x].spr--;
			}
		}
	}
}

void fp() {
	while (!q.empty()) {
		axis now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (map[ny][nx].life == map[ny][nx].spr) {
				if (now.life > map[ny][nx].life) {
					map[ny][nx].life = now.life;
					map[ny][nx].spr = now.life;
				}
			}

		}
	}
}

void canfp() {
	// 배양할 수 있으면 q에 넣기
	for (int y = center - range; y <= center + N + range; y++) {
		for (int x = center - range; x <= center + M + range; x++) {
			if (map[y][x].life > 0 && map[y][x].spr == 0) {
				
				q.push({ y,x, map[y][x].life });
				// 배양가능 q에 넣은애들 배양했다고 표시
				map[y][x].spr = -1;
				
			}
		}
	}
	
}

void lifeDown() {
	for (int y = center - range; y <= center + N + range; y++) {
		for (int x = center - range; x <= center + M + range; x++) {
			if (map[y][x].life > 0 && map[y][x].spr == -1) {
				map[y][x].life--;
			}
		}
	}
}

void count() {
	// 다 끝나고 안죽은놈 세기
	for (int y = center - range; y <= center + N + range; y++) {
		for (int x = center - range; x <= center + M + range; x++) {
			if (map[y][x].life != 0) {
				ans++;
			}
		}
	}
}

void solve() {
	int t = 1;
	while (1) {
		if (t == K + 1) break;
		
		// 배양한애들 life -1 씩
		lifeDown();
		// 비활성이 활성화 되게 -1 씩
		OfftoOn();
		// 배양할 수 있는애들 배양
		fp();
		// 다음 시간에 배양할 수 있는애들 q에 넣기
		canfp();
		

		t++;
	}

	count();
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}