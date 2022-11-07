#include <iostream>
using namespace std;

int N, arr[11][11];
int drY[4] = { 0,1,0,-1 };
int drX[4] = { 1,0,-1,0 };
int start = 1;

void init() {
	start = 2;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			arr[y][x] = 0;
		}
	}
}
void sol(int sy, int sx, int lev) {
	int nowy = sy, nowx = sx;
	while (start <= N*N) {
		int ny = nowy + drY[lev % 4];
		int nx = nowx + drX[lev % 4];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
			lev++;
			continue;
		}
		if (arr[ny][nx] != 0) {
			lev++;
			continue;
		}
		arr[ny][nx] = start;
		start++;
		nowy = ny;
		nowx = nx;
	}
}
void output(int t) {
	cout << "#" << t << "\n";
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << arr[y][x] << " ";
		}
		cout << "\n";
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		init();
		arr[0][0] = 1;
		sol(0,0,0);
		output(t);
	}
	return 0;
}