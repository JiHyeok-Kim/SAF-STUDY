// 어디에 단어가 들어갈 수 있을까
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, K;
int map[16][16], ret;
int used[16][16];
struct str{
	int y;
	int x;
};

void dfs_r(int lev, str now) {
	int nx = now.x + 1;
	used[now.y][now.x] = 1;
	if (nx >= N || map[now.y][nx] == 0) {
		if (lev == K) { ret++; }
		return;
	}

	dfs_r(lev + 1, { now.y, nx });
}

void dfs_d(int lev, str now) {
	int ny = now.y + 1;
	used[now.y][now.x] = 1;
	if (ny >= N || map[ny][now.x] == 0) {
		if (lev == K) { ret++; }
		return;
	}

	dfs_d(lev + 1, { ny, now.x });
}

int main() {
	int TestCase;
	cin >> TestCase;

	for (int t = 1; t <= TestCase; t++) { // test case
		ret = 0;
		cin >> N >> K;

		for (int i = 0; i < N; i++) { // map 초기화 
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				used[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) { // map searching > dfs_r 호출
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					if (used[i][j] == 1) continue;
					dfs_r(1, { i, j });
				}
			}
		}

		for (int i = 0; i < N; i++) { // used 초기화
			for (int j = 0; j < N; j++) {
				used[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) { // map searching > dfs_d 호출
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					if (used[i][j] == 1) continue;
					dfs_d(1, { i, j });
				}
			}
		}
		
		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}