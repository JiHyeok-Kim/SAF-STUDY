#include<iostream>

using namespace std;

int T;
char ch[22][22];
bool d[40];
int r, c;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


int MAX = 0;

void init() {
	for (int a = 0; a < 40; ++a) {
		d[a] = 0;
	}
}

void dfs(int x, int y, int cnt) {
	d[ch[x][y] - 'A'] = 1;
	for (int a = 0; a < 4; ++a) {
		int nx = x + dx[a];
		int ny = y + dy[a];
		if (1 <= nx && nx <= r && ny >= 1 && ny <= c && !d[ch[nx][ny] - 'A']) {

			dfs(nx, ny, cnt + 1);
		}
	}
	d[ch[x][y] - 'A'] = 0;
	if (MAX < cnt) MAX = cnt;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> r >> c;
		for (int a = 1; a <= r; ++a) {
			for (int b = 1; b <= c; ++b) {
				cin >> ch[a][b];

			}
		}

		dfs(1, 1, 1);

		cout << "#" << t << " " << MAX << "\n";

		MAX = 0;
	}
}
