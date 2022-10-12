#include <iostream>
#include <string>
using namespace std;
#define N 100

string map[110];
int ans, t;

void input() {
	ans = 0;
	cin >> t;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
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
			if (flag) return 1;
		}
	}
	return 0;
}

int solve() {
	for (int len = N; len >= 0; len--) {
		for (int k = 0; k < N - len + 1; k++) {
			int garo = isFit(k, len, 'Y');
			int sero = isFit(k, len, 'X');
			if (garo || sero) return len;
		}
	}
}

int main()
{	
	freopen_s(new FILE*, "input.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) {
		input();
		ans = solve();
		cout << "#" << i << " " << ans << "\n";
	}

	return 0;
}