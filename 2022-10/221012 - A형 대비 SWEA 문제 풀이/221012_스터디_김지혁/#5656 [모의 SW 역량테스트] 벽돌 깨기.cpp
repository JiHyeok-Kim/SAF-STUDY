#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int N, W, H, ans, mini;
int og[15][12];
int map[15][12];
int shoot[4];
int directY[4] = { -1,1,0,0 };
int directX[4] = { 0,0,-1,1 };

void init()
{
	cin >> N >> W >> H;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> og[y][x];
		}
	}

	memcpy(map, og, sizeof(map));
	return;
}

void goPang(int ty, int tx, int num)
{
	map[ty][tx] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < num; j++) {
			int dy = ty + directY[i] * j;
			int dx = tx + directX[i] * j;
			if (dy < 0 || dx < 0 || dy >= H || dx >= W) break;
			if (map[dy][dx] == 0) continue;
			if (map[dy][dx] > 1) goPang(dy, dx, map[dy][dx]);
			map[dy][dx] = 0;
		}
	}

	return;
}

void gravity()
{
	stack<int> stck;
	for (int x = 0; x < W; x++) {
		for (int y = 0; y < H; y++) {
			if (map[y][x] == 0) continue;
			stck.push(map[y][x]);
		}
		for (int y = H - 1; y >= 0; y--) {
			if (stck.empty()) {
				map[y][x] = 0;
				continue;
			}
			int n = stck.top();
			stck.pop();
			map[y][x] = n;
		}
	}

	return;
}

int cnt()
{
	int sum = 0;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] == 0) continue;
			sum++;
		}
	}

	return sum;
}

void goShoot(int tx)
{
	for (int y = 0; y < H; y++) {
		if (map[y][tx] == 0) continue;
		if (map[y][tx] == 1) {
			map[y][tx] = 0;
			return;
		}
		goPang(y, tx, map[y][tx]);
		return;
	}

	return;
}

void dfs(int lev)
{
	if (mini == 0) return;
	if (lev == N)
	{
		for (int i = 0; i < N; i++) {
			goShoot(shoot[i]);
			gravity();
		}

		ans = cnt();
		if (ans < mini) mini = ans;

		memcpy(map, og, sizeof(map));
		return;
	}

	for (int x = 0; x < W; x++)
	{
		shoot[lev] = x;

		dfs(lev + 1);

		shoot[lev] = 0;
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();

		ans = 0;
		mini = 21e8;
		dfs(0);

		cout << "#" << tc << " " << mini << "\n";
	}


	return 0;
}