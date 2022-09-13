#include <iostream>
#include <queue>
using namespace std;

int N, M, T;
int ty, tx, gtime;
int MAP[50][50];
bool visited[50][50];
int ret;

typedef struct {
	int y, x;
	int turn;
}POSI;
queue<POSI> q;

const int TYPE[8][3][3] = {
	{
		0,0,0,
		0,0,0,
		0,0,0
	},
	{
		0,1,0,
		1,0,1,
		0,1,0
	},
	{
		0,1,0,
		0,0,0,
		0,1,0
	},
	{
		0,0,0,
		1,0,1,
		0,0,0
	},
	{
		0,1,0,
		0,0,1,
		0,0,0
	},
	{
		0,0,0,
		0,0,1,
		0,1,0
	},
	{
		0,0,0,
		1,0,0,
		0,1,0
	},
	{
		0,1,0,
		1,0,0,
		0,0,0
	}
};

int check(POSI cur, int ny, int nx) {
	int type = MAP[ny][nx];
	for (int dirY = ny - 1; dirY <= ny + 1; ++dirY) {
		for (int dirX = nx - 1; dirX <= nx + 1; ++dirX) {
			if (dirY < 0 || dirY >= N || dirX < 0 || dirX >= M) continue;
			if (TYPE[type][dirY - ny + 1][dirX - nx + 1] == 1 && dirY == cur.y && dirX == cur.x) return 1;
		}
	}
	return 0;
}

void BFS() {
	while (!q.empty()) {
		POSI cur = q.front();	q.pop();
		visited[cur.y][cur.x] = true;
		int type = MAP[cur.y][cur.x];
		if (cur.turn >= gtime) break;

		for (int dirY = cur.y - 1; dirY <= cur.y + 1; ++dirY) {
			for (int dirX = cur.x - 1; dirX <= cur.x + 1; ++dirX) {
				if (TYPE[type][dirY - cur.y + 1][dirX - cur.x + 1] == 0) continue;
				int ny = dirY;
				int nx = dirX;
				if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] == true) continue;
				if (MAP[ny][nx] == 0) continue;
				if (check(cur, ny, nx) == 0) continue;
				visited[ny][nx] = true;
				ret++;
				q.push({ ny,nx,cur.turn + 1 });
			}
		}
	}
}

void Solve() {
	ret++;
	q.push({ ty,tx,1 });
	BFS();
}

void init() {
	ret = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			visited[y][x] = false;
			MAP[y][x] = 0;
		}
	}
	while (!q.empty()) {
		q.pop();
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M >> ty >> tx >> gtime;
		init();
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				cin >> MAP[y][x];
			}
		}

		Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}