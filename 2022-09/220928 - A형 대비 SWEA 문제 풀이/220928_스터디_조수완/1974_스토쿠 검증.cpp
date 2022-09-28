#include <iostream>
using namespace std;

int map[10][10], result;
void input() {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> map[y][x];
		}
	}
}
int chkY() {
	for (int x = 0; x < 9;x++) {
		int dat[10] = { 0 };
		for (int y = 0; y < 9; y++) {
			dat[map[y][x]]++;
			if (dat[map[y][x]] > 1) return 0;
		}
	}
	return 1;
}
int chkX() {
	for(int y = 0; y < 9;y++) {
		int dat[10] = { 0 };
		for (int x = 0; x < 9; x++) {
			dat[map[y][x]]++;
			if (dat[map[y][x]] > 1) return 0;
		}
	}
	return 1;
}
int chk3() {
	for (int y = 0; y < 9; y += 3) {
		for (int x = 0; x < 9; x += 3) {
			int dat[10] = { 0 };
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					dat[map[y + i][x + j]]++;
					if (dat[map[y + i][x + j]] > 1) return 0;
				}
			}
		}
	}
	return 1;
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		result = chkY();
		if (result == 0) {
			cout << "#" << t << " " << result << "\n";
			continue;
		}
		result = chkX();
		if (result == 0) {
			cout << "#" << t << " " << result << "\n";
			continue;
		}
		result = chk3();
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