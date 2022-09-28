#include <iostream>
#include <queue>
using namespace std;

int T, N;
char MAP[50][50];
bool visited[50][50];
int ret;

typedef struct {
	int y, x;
	int turn;
}POSI;
queue<POSI> q;

const int dy[] = { 0,0,-1,1 };
const int dx[] = { -1,1,0,0 };

void BFS() {
	while (!q.empty()) {
		POSI cur = q.front();	q.pop();
		visited[cur.y][cur.x] = true;
		ret += (MAP[cur.y][cur.x] - '0');
		if (cur.turn == N / 2 + 1) continue;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visited[ny][nx] == true) continue;
			visited[ny][nx] = true;
			q.push({ ny,nx,cur.turn + 1 });
		}
	}
}

int Solve() {
	ret = 0;
	q.push({ N / 2,N / 2,1 });
	BFS();
	return ret;
}

void init() {
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
		}

		int ret = Solve();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}