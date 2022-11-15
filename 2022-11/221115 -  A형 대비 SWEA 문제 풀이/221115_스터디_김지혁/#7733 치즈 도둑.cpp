#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Coord {
	int y, x;
};

int N, maxi, ans;
int cheese[100][100];
int visited[100][100];
bool used[100];

void init()
{
	ans = 0;
	maxi = 0;
	memset(cheese, 0, sizeof(cheese));
	memset(used, false, sizeof(used));

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> cheese[y][x];
			maxi = max(maxi, cheese[y][x]);
			used[cheese[y][x]] = true;
		}
	}

	return;
}

void eat(int day)
{
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (cheese[y][x] == day) cheese[y][x] = -1;

	return;
}

int BFS()
{
	memset(visited, 0, sizeof(visited));

	int directY[] = { -1, 1, 0, 0 };
	int directX[] = { 0, 0, -1, 1 };

	int cnt = 0;
	queue<Coord> q;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (cheese[y][x] == -1) continue;
			if (visited[y][x] > 0) continue;

			cnt++;
			q.push({ y, x });

			while (!q.empty())
			{
				Coord now = q.front();
				q.pop();

				for (int i = 0; i < 4; i++)
				{
					int ny = now.y + directY[i];
					int nx = now.x + directX[i];
					if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
					if (cheese[ny][nx] == -1) continue;
					if (visited[ny][nx] > 0) continue;
					visited[ny][nx] = cnt;
					q.push({ ny, nx });
				}
			}


		}
	}

	return cnt;
}

void solve()
{
	int cnt = 1;
	for (int i = 1; i <= maxi; i++) {
		if (used[i] == false) continue;
		eat(i);
		cnt = max(cnt, BFS());
	}

	ans = cnt;
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
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}