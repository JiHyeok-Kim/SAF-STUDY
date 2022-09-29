#include <iostream>
#include <queue>
using namespace std;

int T, N;
char MAP[300][301];
bool visited[300][300];
int total, click;

typedef struct {
	int y, x;
}POSI;
queue<POSI> q;

const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,1,1,1,0,-1,-1,-1 };

bool isValid(int ty, int tx) {
	for (int dir = 0; dir < 8; ++dir) {
		int ny = ty + dy[dir];
		int nx = tx + dx[dir];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (MAP[ny][nx] == '*') return false;
	}
	return true;
}

void BFS() {
	while (!q.empty()) {
		POSI cur = q.front();	q.pop();
		if (!isValid(cur.y, cur.x)) continue;
		visited[cur.y][cur.x] = true;

		for (int dir = 0; dir < 8; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visited[ny][nx] == true) continue;
			if (MAP[ny][nx] == '.') {
				visited[ny][nx] = true;
				total--;
				q.push({ ny,nx });
			}
		}
	}
}

int Solve() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (MAP[y][x] == '.' && isValid(y, x)) {
				total--;
				click++;
				q.push({ y,x });
				BFS();
			}
		}
	}

	return click + total;
}

void init() {
	total = 0, click = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			visited[y][x] = false;
		}
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		init();
		for (int y = 0; y < N; ++y) {
			cin >> MAP[y];
			for (int x = 0; x < N; ++x) {
				if (MAP[y][x] == '.') total++;
			}
		}

		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}