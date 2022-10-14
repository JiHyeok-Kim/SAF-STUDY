#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Coord {
	int y, x;
};

int N;
int map[20][20];

void init()
{
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> map[y][x];

	return;
}

int maxi;
int visited[20][20];
int dat[101];
int directY[] = { 1,1,-1,-1 }; //¿ìÇÏ ÁÂÇÏ ÁÂ»ó ¿ì»ó
int directX[] = { 1,-1,-1,1 };

void dfs(Coord now, int lev, Coord st) 
{
	if (now.y == st.y && now.x == st.x && visited[now.y][now.x])
	{
		maxi = max(maxi, visited[now.y][now.x]);
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		int ny = now.y + directY[lev + i];
		int nx = now.x + directX[lev + i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (lev + i >= 4) continue;
		if (dat[map[ny][nx]] != 0) continue;
		if (visited[ny][nx] > 0) continue;

		dat[map[ny][nx]] = 1;
		visited[ny][nx] = visited[now.y][now.x] + 1;
		dfs({ ny, nx }, lev + i, st);
		visited[ny][nx] = 0;
		dat[map[ny][nx]] = 0;
	}

	return;
}

int ans()
{
	maxi = -1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			Coord st = { y, x };
			dfs(st, 0, st);
		}
	}

	return maxi;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		cout << "#" << tc << " " << ans() << "\n";
	}

	return 0;
}