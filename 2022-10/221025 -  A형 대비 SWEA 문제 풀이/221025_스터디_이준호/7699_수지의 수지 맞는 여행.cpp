#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int H, W, ans;
string map[21];
int dat[27];
int used[21][21];
int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };

void init() {
	ans = 1;
	memset(dat, 0, sizeof(dat));
	memset(used, 0, sizeof(used));
	for (int i = 0; i < 21; i++) {
		map[i] = "";
	}

}
void input() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> map[i];
	}
}

bool isAgain(char tar) {
	if (dat[tar - 'A'] == 2) return 1;
	return 0;
}

void dfs(int cnt, int nowY, int nowX) {
	if (isAgain(map[nowY][nowX])) {
		ans = max(cnt, ans);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = nowY + ditY[i];
		int nx = nowX + ditX[i];
		if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
		if (used[ny][nx] == 1) continue;
		used[ny][nx] = 1;
		dat[map[ny][nx] - 'A']++;
		
		dfs(cnt + 1, ny, nx); 
		
		dat[map[ny][nx] - 'A']--;
		used[ny][nx] = 0;
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
		dat[map[0][0] - 'A']++;
		used[0][0] = 1;
		
		dfs(0, 0, 0);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}