#include <iostream>
using namespace std;
int N, result;
char map[101][101];

void input() {
	cin >> N; result = 0;
	for (int y = 0; y < 100; y++)for (int x = 0; x < 100; x++)cin >> map[y][x];
}
int isFit(int start, int len, char coor) {
	int flag = 1;
	if (coor == 'X') {
		for (int y = 0; y < 100; y++) {
			flag = 1;
			for (int i = 0; i < len / 2; i++) {
				if (map[y][start + i] != map[y][start + len - i - 1]) {
					flag = 0; break;
				}
			}
			if (flag) return 1;
		}
	}
	if (coor == 'Y') {
		for (int x = 0; x < 100; x++) {
			flag = 1;
			for (int i = 0; i < len / 2; i++) {
				if (map[start + i][x] != map[start + len - i - 1][x]) {
					flag = 0; break;
				}
			}
			if(flag) return 1;
		}
	}
	return 0;
}
int findResult() {
	for (int len = 100; len >= 0; len--) {
		for (int i = 0; i < 100 - len + 1; i++) {
			int flagY = isFit(i, len, 'Y');
			int flagX = isFit(i, len, 'X');
			if (flagY || flagX) return len;
		}
	}
}
void solve() {
	for (int t = 1; t <= 10; t++) {
		input();
		result = findResult();
		cout << "#" << t << " " << result << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}