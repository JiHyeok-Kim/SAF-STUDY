#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct pos {
	int y;
	int x;
};

char map[300][300];
bool zero[300][300];
int n;
int cnt;
int answer = 0;

int dy[8] = { 0,0,-1,-1,-1,1,1,1 };
int dx[8] = { -1,1,1,0,-1,1,0,-1 };

bool isSafe(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
		if (map[ny][nx] != '.') return false;
	}

	return true;
}

void search() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (zero[i][j]) continue;
			if (map[i][j] == '.' && isSafe(i,j)) {
				queue<pos> q;
				q.push({ i,j });

				zero[i][j] = true;
				cnt--;
				answer++;

				while (!q.empty()) {
					pos now = q.front();
					q.pop();

					if (!isSafe(now.y, now.x)) continue;

					for (int i = 0; i < 8; i++) {
						int ny = now.y + dy[i];
						int nx = now.x + dx[i];
						if (ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
						if (zero[ny][nx] == true) continue;
						zero[ny][nx] = true;
						cnt--;
						q.push({ ny, nx });
					}
				}
			}
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		answer = 0;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < n; j++) {
				map[i][j] = str[j];
				zero[i][j] = false;
				if (map[i][j] == '.') cnt++;
			}
		}

		search();

		answer += cnt;

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}