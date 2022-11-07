#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};

int H, W, maxi;
int map[10][25];
int made[10][25];
int directY[] = { -1, 1, 0, 0 };
int directX[] = { 0, 0, -1, 1 };
int validY[] = { 0, 0, 1, 1 };
int validX[] = { 0, 1, 0, 1 };

void init()
{
	maxi = 0;
	memset(map, 0, sizeof(map));

	cin >> H >> W;
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			cin >> map[y][x];

	return;
}

int isValid(int ty, int tx)
{
	for (int i = 0; i < 4; i++)
	{
		int dy = ty + validY[i];
		int dx = tx + validX[i];
		if (dy < 0 || dx < 0 || dy >= H || dx >= W) return 0;
		if (made[dy][dx] == 1) return 0;
	}

	for (int i = 0; i < 4; i++)
	{
		int dy = ty + validY[i];
		int dx = tx + validX[i];
		made[dy][dx] = 1;
	}

	return 1;
}

int ff(int ty, int tx, int cnt)
{
	int visited[10][25];
	memcpy(made, map, sizeof(made));
	memset(visited, 0, sizeof(visited));

	queue<Node> q;
	q.push({ ty , tx });
	visited[ty][tx] = 1;
	cnt += isValid(ty, tx);

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (made[ny][nx] == 0) cnt += isValid(ny, nx);
			if (visited[ny][nx] == 1) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}

	return cnt;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				if (map[y][x] == 1) continue;
				int cnt = ff(y, x, 0);
				maxi = max(maxi, cnt);
			}
		}

		cout << "#" << tc << " " << maxi << "\n";
	}

	return 0;
}