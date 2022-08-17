#include <iostream>
#include <algorithm>
using namespace std;

int N, Q, map[550][550];
int acc[550][550][10];
int drY[3] = { -1,0,-1 };
int drX[3] = { 0,-1,-1 };
int hap[3] = { 1,1,-1 };
int A, B, C, D, maxCnt;

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 0) continue;
			acc[y][x][map[y][x]]++;
			for (int i = 0; i < 3; i++) {
				int ny = y + drY[i];
				int nx = x + drX[i];
				if (map[ny][nx] == 0) continue;
				for (int j = 1; j < 10; j++) {
					acc[y][x][j] = acc[y][x][j] + hap[i] * acc[ny][nx][j];
				}
			}
		}
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> A >> B >> C >> D;
		int ans[10] = { 0, };
		for (int j = 1; j < 10; j++) {
			ans[j] = acc[C][D][j];
		}
		for (int j = 1; j < 10; j++) {
			ans[j] -= acc[A - 1][D][j];
		}
		for (int j = 1; j < 10; j++) {
			ans[j] -= acc[C][B - 1][j];
		}
		for (int j = 1; j < 10; j++) {
			ans[j] += acc[A - 1][B - 1][j];
		}
		int maxVal = -1;
		for (int i = 9; i > 0; i--) {
			if (ans[i] >= maxVal) {
				maxVal = ans[i];
				maxCnt = i;

			}
		}
		cout << maxCnt << '\n';
	}
	return 0;
}