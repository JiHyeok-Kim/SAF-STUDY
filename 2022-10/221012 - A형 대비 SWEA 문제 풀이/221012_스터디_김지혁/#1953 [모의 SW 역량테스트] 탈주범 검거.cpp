#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y;
	int x;
	int lev;
};

int T;
int N, M, R, C, L;
int map[50][50];
int visited[50][50];
int ans;
int directY[4] = { -1,1,0,0 }; // ╩С го аб ©Л
int directX[4] = { 0,0,-1,1 }; // ╩С го аб ©Л

int pipeNow[8][4] = {
	{},
	{1,1,1,1}, // ╩С го аб ©Л
	{1,1,0,0},
	{0,0,1,1},
	{1,0,0,1},
	{0,1,0,1},
	{0,1,1,0},
	{1,0,1,0},
};

int pipeNext[8][4] = {
	{},
	{1,1,1,1}, // го ╩С ©Л аб
	{1,1,0,0},
	{0,0,1,1},
	{0,1,1,0},
	{1,0,1,0},
	{1,0,0,1},
	{0,1,0,1},
};

void catchTaljoo()
{
	queue<Node> q;
	q.push({ R,C, 1 });
	visited[R][C] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		if (now.lev == L) break;

		for (int i = 0; i < 4; i++)
		{
			int dy = now.y + directY[i];
			int dx = now.x + directX[i];
			if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue;
			if (map[dy][dx] == 0) continue;
			if (visited[dy][dx] == 1) continue;
			if (pipeNow[map[now.y][now.x]][i] == 0 || pipeNext[map[dy][dx]][i] == 0) continue;

			visited[dy][dx] = 1;
			q.push({ dy, dx, now.lev + 1 });
		}
	}

	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		ans = 0;
		cin >> N >> M >> R >> C >> L;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				cin >> map[y][x];
			}
		}

		catchTaljoo();

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (visited[y][x] == 1) ans++;
			}
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}