#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

int map[4][4];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

unordered_map<int, int> um;

void solve(int y, int x, int lev, int val)
{
	if (lev == 7) {
		if (um.count(val) == 0) {
			um[val] = 1;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
		val += map[ny][nx] * (pow(10, lev));
		solve(ny, nx, lev + 1, val);
		val -= map[ny][nx] * (pow(10, lev));
	}
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		um.clear();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				solve(i, j, 1, map[i][j]);
			}
		}

		cout << "#" << t << " " << um.size() << '\n';
	}
	return 0;
}