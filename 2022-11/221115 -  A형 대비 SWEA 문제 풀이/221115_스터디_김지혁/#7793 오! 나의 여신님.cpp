#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct Coord {
	int y, x;
};

int N, M, valid;
string map[50];
int times[50][50];
int devil[50][50];
Coord st, fn;

void init()
{
	fill(&devil[0][0], &devil[0][0] + 50 * 50, 21e8);
	fill(¡¿[0][0], ¡¿[0][0] + 50 * 50, 21e8);
	int flag = 0;
	valid = 0;

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		cin >> map[y];
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 'S') st = { y, x };
			if (map[y][x] == 'D') fn = { y, x };
			if (map[y][x] == '*') devil[y][x] = 0;
		}
	}

	return;
}

void Dijkstra()
{
	int lev = 0;
	int directY[] = { -1, 1, 0, 0 };
	int directX[] = { 0, 0, -1, 1 };

	times[st.y][st.x] = 0;
	queue<Coord> q;
	q.push(st);

	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();

		int nowTimes = times[now.y][now.x];

		if (lev <= nowTimes) {
			lev++;
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < M; x++) {
					if (devil[y][x] == 21e8 || devil[y][x] == lev) continue;
					for (int i = 0; i < 4; i++) {
						int dy = y + directY[i];
						int dx = x + directX[i];
						if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue;
						if (map[dy][dx] != '.') continue;
						if (lev < devil[dy][dx]) devil[dy][dx] = lev;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx] == 'X' || map[ny][nx] == '*') continue;
			if (nowTimes + 1 < times[ny][nx] && nowTimes + 1 < devil[ny][nx]) times[ny][nx] = nowTimes + 1;
			else continue;
			if (map[ny][nx] == 'D') return;
			q.push({ ny, nx });
		}
	}

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		Dijkstra();
		valid = times[fn.y][fn.x];
		cout << "#" << tc << " ";
		(valid != 21e8) ? cout << valid << "\n" : cout << "GAME OVER\n";
	}

	return 0;
}