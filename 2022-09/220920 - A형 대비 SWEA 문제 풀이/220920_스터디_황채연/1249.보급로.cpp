#include <iostream>
#include <queue>
using namespace std;

int T, N;
char MAP[100][101];
int score[100][100];

typedef struct {
	int y, x;
	int point;
}BLOCK;
queue<BLOCK> q;

const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };

void BFS() {
	q.push({ 0,0,MAP[0][0] - 48 });
	while (!q.empty()) {
		BLOCK cur = q.front();	q.pop();
		if (score[cur.y][cur.x] >= cur.point) score[cur.y][cur.x] = cur.point;
		else continue;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			
			int npoint = cur.point + MAP[ny][nx] - 48;
			if (score[ny][nx] > npoint) {
				score[ny][nx] = npoint;
				q.push({ ny, nx, npoint });
			}
		}
	}
}

int Solve() {
	BFS();
	return score[N - 1][N - 1];
}

void init() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			score[y][x] = 21e8;
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