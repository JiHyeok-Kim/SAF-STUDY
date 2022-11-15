#include <iostream>
#include <cstring>
using namespace std;

int H, W, K, ans, ansFlag;
int Map[15][22];
int tmpMap[15][22];
int path[15], used[15], path2[15];

void init() {
	ans = 0;
	for (int y = 0; y < 15; y++) {
		path[y] = used[y] = path2[y] = 0;
		for (int x = 0; x < 22; x++) {
			Map[y][x] = tmpMap[y][x] = 0;
		}
	}
}
void input() {
	cin >> H >> W >> K;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> Map[y][x];
		}
	}
}

void Inject(int rowCnt) {
	memcpy(tmpMap, Map, sizeof(Map));

	for (int y = 0; y < rowCnt; y++) {
		for (int x = 0; x < W; x++) {
			tmpMap[path[y]][x] = path2[y];
		}
	}
}

bool Check() {
	for (int x = 0; x < W; x++) {
		int cnt = 1;
		int flag = 0;
		for (int y = 0; y < H - 1; y++) {
			if (tmpMap[y][x] == tmpMap[y + 1][x]) {
				cnt++;
			}
			else cnt = 1;

			if (cnt == K) { flag = 1; break; }
		}
		if (flag == 0) return 0;
	}
	return 1;
}


void dfs2(int lev, int rowCnt) {
	if (lev == rowCnt) {
		Inject(rowCnt);
		if (Check()) ansFlag = 1;
		return;
	}

	if (ansFlag == 1) return;

	for (int i = 0; i < 2; i++) {
		path2[lev] = i;
		dfs2(lev + 1, rowCnt);
		path2[lev] = 0;
	}
}

void dfs(int lev, int start, int rowCnt) {
	if (lev == rowCnt) {
		if (ansFlag == 1) return;
		dfs2(0, rowCnt);
		return;
	}

	if (ansFlag == 1) return;

	for (int i = start; i < H; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = i;
		dfs(lev + 1, i, rowCnt);
		path[lev] = 0;
		used[i] = 0;
	}
}

void solve() {
	// 0뽑
	memcpy(tmpMap, Map, sizeof(Map));
	if (Check()) return;
	int de = 1;
	// 1뽑, 2뽑, 3뽑...
	ansFlag = 0;
	for (int k = 1; k <= H; k++) {
		dfs(0, 0, k);
		if (ansFlag == 1) { ans = k; break; }
	}

}

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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