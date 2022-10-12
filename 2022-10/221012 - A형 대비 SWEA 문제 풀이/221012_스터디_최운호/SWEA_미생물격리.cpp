#include <iostream>
#include <vector>
using namespace std;

struct info {
	int y;
	int x;
	int cell;
	int dir;
	int state;
};

struct map {
	int cnt;
	vector<int> group;
};

info cells[1000];
map arr[100][100];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0, 0,0,-1,1 };

int changeDir(int dir) {
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else if (dir == 4) return 3;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n, m, k;
		cin >> n >> m >> k;

		for (int i = 0; i < k; i++) {
			int col, row, cnt, d;
			cin >> col >> row >> cnt >> d;
			cells[i].y = col;
			cells[i].x = row;
			cells[i].cell = cnt;
			cells[i].dir = d;
			cells[i].state = 0;
		}

		int curTime = 0;

		while (curTime < m) {
			for (int i = 0; i < k; i++) {
				if (cells[i].state) continue;

				int ny = cells[i].y + dy[cells[i].dir];
				int nx = cells[i].x + dx[cells[i].dir];
				if (ny == 0 || nx == 0 || ny == n - 1 || nx == n - 1) {
					cells[i].cell /= 2;
					cells[i].dir = changeDir(cells[i].dir);
				}

				arr[ny][nx].cnt++;
				arr[ny][nx].group.push_back(i);

				cells[i].y = ny;
				cells[i].x = nx;
				if (cells[i].cell == 0) cells[i].state = 1;
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j].cnt > 1) {
						int total = cells[arr[i][j].group[0]].cell;
						int idx = arr[i][j].group[0];
						for (int x = 1; x < arr[i][j].cnt; x++) {
							total += cells[arr[i][j].group[x]].cell;
							if (cells[idx].cell < cells[arr[i][j].group[x]].cell) {
								cells[idx].state = 1;
								idx = arr[i][j].group[x];
							}
							else cells[arr[i][j].group[x]].state = 1;
						}
						cells[idx].cell = total;
					}
					arr[i][j].cnt = 0;
					arr[i][j].group.clear();
				}
			}
			
			curTime++;
		}
		int result = 0;
		for (int i = 0; i < k; i++) {
			if (cells[i].state == 1) continue;
			result += cells[i].cell;
		}

		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}