#include <iostream>
using namespace std;

int map[25][25];
int flag, xcnt, cnt, N, len;

int isX(int x) {
	int xval = map[0][x], xflag = -1;
	flag = 0, cnt = 1, xcnt = 0;
	for (int y = 1; y < N; y++) {
		flag = xval - map[y][x];
		if (flag == 0) {
			cnt++;
			if (y == N - 1) {
				if (xflag == -1) continue;
				if (cnt < len) return 0;
				continue;
			}
			continue;
		}
		if (flag != -1 && flag != 1) return 0;
		if (flag == -1) {
			xcnt = cnt;
			cnt = 1;
			xval = map[y][x];
			if (xflag == 1) if (xcnt < 2 * len) return 0;
			if (y == N - 1) continue;
			if (xcnt < len) return 0;
			xflag = -1;
		}
		if (flag == 1) {
			xcnt = cnt;
			cnt = 1;
			xval = map[y][x];
			if (y == N - 1) return 0;
			if (xflag == -1) {
				xflag = 1;
				continue;
			}
			if (xcnt < len) return 0;
			xflag = 1;
		}
	}
	return 1;
}
int isY(int y) {
	int xval = map[y][0], xflag = -1;
	flag = 0, cnt = 1, xcnt = 0;
	for (int x = 1; x < N; x++) {
		flag = xval - map[y][x];
		if (flag == 0) {
			cnt++;
			if (x == N - 1) {
				if (xflag == -1) continue;
				if (cnt < len) return 0;
				continue;
			}
			continue;
		}
		if (flag != -1 && flag != 1) return 0;
		if (flag == -1) {
			xcnt = cnt;
			cnt = 1;
			xval = map[y][x];
			if (xflag == 1) if (xcnt < 2 * len) return 0;
			if (x == N - 1) continue;
			if (xcnt < len) return 0;
			xflag = -1;
		}
		if (flag == 1) {
			xcnt = cnt;
			cnt = 1;
			xval = map[y][x];
			if (x == N - 1) return 0;
			if (xflag == -1) {
				xflag = 1;
				continue;
			}
			if (xcnt < len) return 0;
			xflag = 1;
		}
	}
	return 1;
}
int sol() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += isX(i);
		ans += isY(i);
	}
	return ans;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> len;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
			}
		}
		int ans = sol();
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}