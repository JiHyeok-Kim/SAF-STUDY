#include <iostream>
using namespace std;

int N, ans;
int map[20][20];
int used[20][20];
int ditY[] = { -1,1,1,-1 };
int ditX[] = { 1,1,-1,-1 };
int dat[101];

struct Coord {
	int y;
	int x;
};

void init() {
	ans = -1;
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			map[y][x] = 0;
		}
	}
}
void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}


void dfs(Coord st, int cnt, Coord now) {
	if (cnt > 0 && now.y == st.y && now.x == st.x) {
		ans = max(ans, used[now.y][now.x]);
		return;
	}
	
	for (int i = 0; i < 2; i++) {
		int ny = now.y + ditY[cnt + i];
		int nx = now.x + ditX[cnt + i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (cnt + i >= 4) continue;
		if (dat[map[ny][nx]] == 1) continue;
		
		if (used[ny][nx] == 0)
		{
			dat[map[ny][nx]]++;
			used[ny][nx] = used[now.y][now.x] + 1;
			dfs(st, cnt + i, { ny,nx });
			used[ny][nx] = 0;
			dat[map[ny][nx]]--;
		}

	}

}

void solve() {
	
	for (int y = 1; y <= N - 2; y++) {
		for (int x = 0; x <= N - 3; x++) {
			Coord st = { y,x };
			dfs(st, 0, st);
		}
	}

}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}