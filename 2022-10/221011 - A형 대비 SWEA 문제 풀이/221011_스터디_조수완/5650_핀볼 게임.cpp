#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct Node {
	int y, x;
};
vector<Node> hole[20];
int N, map[110][110], ans;
int drY[4] = { -1,0,1,0 };
int drX[4] = { 0,1,0,-1 };
int dir1[6][4] = { {0,0,0,0},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,0,3,1},{2,3,0,1} };
int Wall(int dir) {
	if (dir == 0) return 2;
	if (dir == 1) return 3;
	if (dir == 2) return 0;
	if (dir == 3) return 1;
	return dir;
}
Node Hole(int num,int nowy, int nowx) {
	for (int i = 0; i < hole[num].size(); i++) {
		if (nowy != hole[num][i].y || nowx != hole[num][i].x) {
			return { hole[num][i].y,hole[num][i].x };
		}
	}
	return { nowy,nowx };
}
int dfs(int y, int x, int dir,int fy,int fx) {
	int cnt = 0, nowy = y, nowx = x, ndir = dir;
	int ny, nx;
	while(1){
		ny = nowy + drY[ndir];
		nx = nowx + drX[ndir];
		if (ny < 1 || nx < 1 || ny > N || nx > N) {
			ndir = Wall(ndir);
			nowy = ny;
			nowx = nx;
			cnt++;
			continue;
		}
		int val = map[ny][nx];
		if ((ny == fy && nx == fx) || val == -1) return cnt;
		if (0 < val && val < 6) {
			ndir = dir1[val][ndir];
			nowy = ny;
			nowx = nx;
			cnt++;
			continue;
		}
		else if (val > 5) {
			Node nCoor = Hole(val, ny, nx);
			nowy = nCoor.y;
			nowx = nCoor.x;
			continue;
		}
		nowy = ny;
		nowx = nx;
	}
	return cnt;
}

void sol() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (map[y][x] != 0)continue;
			for (int i = 0; i < 4; i++) {
				int cnt = dfs(y, x, i, y, x);
				ans = max(ans, cnt);
			}
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 6; i < 13; i++) hole[i].clear();
		memset(map, 0, sizeof(map));
		ans = 0;
		cin >> N;
		for (int y = 1; y <= N; y++) {
			for(int x = 1; x <= N; x++){
				cin >> map[y][x];
				if (map[y][x] >= 6) {
					hole[map[y][x]].push_back({y,x});
				}
			}
		}
		sol();
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}