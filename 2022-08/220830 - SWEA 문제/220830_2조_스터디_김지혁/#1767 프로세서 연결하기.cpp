#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct Node {
	int y;
	int x;
};

int N, rest, maxi, ans;
int map[12][12];
int used[12][12];
int directY[4] = { -1,1,0,0 };
int directX[4] = { 0,0,-1,1 };
vector<Node> v;

void init()
{
	v.clear();
	rest = 0;
	ans = 0;
	maxi = 0;
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 0) continue;
			if (y == 0 || x == 0 || y == N - 1 || x == N - 1) {
				rest++;
				continue;
			}
			v.push_back({ y, x });
		}
	}

	memcpy(used, map, sizeof(used));
	return;
}

int connect(int lev, int idx)
{
	int len = 0;
	Node tar = v[lev];
	for (int i = 1; i < N; i++) {
		int dy = tar.y + directY[idx] * i;
		int dx = tar.x + directX[idx] * i;
		if (dy < 0 || dx < 0 || dy >= N || dx >= N) {
			len = i;
			break;
		}
		if (used[dy][dx] == 1) {
			return 0;
		}
	}
	
	for (int i = 1; i < len; i++) {
		int dy = tar.y + directY[idx] * i;
		int dx = tar.x + directX[idx] * i;
		used[dy][dx] = 1;
	}

	return len - 1;
}

void dfs(int lev, int core, int len)
{
	if (lev == N - rest) {
		int flag = 0;
		if (core >= maxi) {
			if (core == maxi && len > ans) flag = 1;
			maxi = core;
			if (flag == 0) ans = len;
		}

		return;
	}


	for (int i = 0; i < 4; i++) {

		int up = 0;
		int add = connect(lev, i);

		if (add > 0) up = 1;

		dfs(lev + 1, core + up, len + add);
		
		for (int j = 1; j <= add; j++) {
			int dy = v[lev].y + directY[i] * j;
			int dx = v[lev].x + directX[i] * j;
			used[dy][dx] = 0;
		}
	}
	return;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();

		dfs(0, 0, 0);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}