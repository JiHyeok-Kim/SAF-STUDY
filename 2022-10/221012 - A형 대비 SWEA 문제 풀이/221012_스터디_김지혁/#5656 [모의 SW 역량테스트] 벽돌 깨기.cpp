#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int N, W, H, mini;
int map[15][12];
int temp[15][12];
int bucket[4];
int directY[4] = { -1,1,0,0 }; //»óÇÏÁÂ¿ì
int directX[4] = { 0,0,-1,1 };

void init()
{
	mini = 21e8;
	memset(map, 0, sizeof(map));

	cin >> N >> W >> H;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
		}
	}

	memcpy(temp, map, sizeof(temp));
	return;
}

void pang(int ty, int tx, int num)
{
	temp[ty][tx] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < num; j++) {
			int dy = ty + directY[i] * j;
			int dx = tx + directX[i] * j;
			if (dy < 0 || dx < 0 || dy >= H || dx >= W) break;
			else if (temp[dy][dx] == 0) continue;
			else if (temp[dy][dx] == 1) { temp[dy][dx] = 0; continue; }
			else if (temp[dy][dx] > 1) pang(dy, dx, temp[dy][dx]);
			temp[dy][dx] = 0;
		}
	}

	return;
}

void gravity()
{
	stack<int> st;
	for (int x = 0; x < W; x++) {
		for (int y = 0; y < H; y++) {
			if (temp[y][x] == 0) continue;
			st.push(temp[y][x]);
			temp[y][x] = 0;
		}

		for (int y = H - 1; y >= 0; y--) {
			if (st.empty()) break;
			else {
				int n = st.top();
				st.pop();
				temp[y][x] = n;
			}
		}
	}

	return;
}

void shoot()
{
	for (int i = 0; i < N; i++) {
		int flag = 0;
		int x = bucket[i];
		for (int y = 0; y < H; y++) {
			if (temp[y][x] == 0) continue;
			if (temp[y][x] == 1) {
				temp[y][x] = 0;
				break;
			}
			flag = 1;
			pang(y, x, temp[y][x]);
			break;
		}
		if (flag == 0) continue;
		gravity();
	}

	return;
}

int cnt()
{
	int num = 0;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (temp[y][x] == 0) continue;
			num++;
		}
	}

	return num;
}

void dfs(int lev)
{
	if (mini == 0) return;
	if (lev == N) {
		shoot();
		mini = min(mini, cnt());

		memcpy(temp, map, sizeof(temp));
		return;
	}

	for (int i = 0; i < W; i++) {

		bucket[lev] = i;

		dfs(lev + 1);

		bucket[lev] = -1;
	}

	return;
}

int ans()
{
	dfs(0);

	return mini;
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
		cout << "#" << tc << " " << ans() << "\n";
	}

	return 0;
}