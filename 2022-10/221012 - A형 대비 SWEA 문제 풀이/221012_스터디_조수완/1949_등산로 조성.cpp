#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N, K, maxDist = -1;
int map[10][10];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
int used[10][10];
void getDist(int y, int x, int val, int lev, int flag) {
	if (val < 1) {
		maxDist = max(maxDist, lev);
		return;
	}
	if (flag == 0 && val == 1) {
		maxDist = max(maxDist, lev);
		return;
	}
	int flag1 = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + drY[i];
		int nx = x + drX[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (used[ny][nx] == 1) continue;
		if (flag && map[ny][nx] >= val) {
			if ((map[ny][nx] - val) < K) {
				int nVal = val - 1;
				flag1 = 0;
				used[ny][nx] = 1;
				getDist(ny, nx, nVal, lev + 1, 0);
				used[ny][nx] = 0;
			}
		}
		if (map[ny][nx] >= val) continue;
		used[ny][nx] = 1;
		getDist(ny, nx, map[ny][nx], lev + 1, flag);
		used[ny][nx] = 0;
		flag1 = 0;
	}
	if(flag1) maxDist = max(maxDist, lev);
}


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		int maxVal = 0;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
				maxVal = max(maxVal, map[y][x]);
			}
		maxDist = -1;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] == maxVal) {
					memset(used, 0, sizeof(int));
					used[y][x] = 1;
					getDist(y, x, map[y][x], 1, 1);
					used[y][x] = 0;
				}
			}
		}
		cout << "#" << t << " " << maxDist << '\n';
	}
	return 0;
}