
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int x;
	int y;
};
int T, N;

int game[101][101];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int block[6][4] = { {0,0,0,0},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,0,3,1},{2,3,0,1} };
unordered_map<int, Node> wormhole;

void init() {
	wormhole.clear();
	memset(game, 0, sizeof(game));
}



int go(int x, int y, int d) {
	int nx = x;
	int ny = y;
	int cnt = 0;
	while (1) {
		nx = nx + mov[d][0];
		ny = ny + mov[d][1];
		if (nx == x && ny == y)
			return cnt;

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			d = (d + 2) % 4;
			++cnt;
			continue;
		}
		if (game[nx][ny] == -1)
			return cnt;

		if (game[nx][ny] >= 1 && game[nx][ny] <= 5) {
			d = block[game[nx][ny]][d];
			++cnt;
		}
		else if (game[nx][ny] >= 6 && game[nx][ny] <= 10) {
			Node tmp = wormhole[game[nx][ny]];
			Node ttmp = wormhole[-game[nx][ny]];
			if (tmp.x == nx && tmp.y == ny) {
				nx = ttmp.x;
				ny = ttmp.y;
			}
			else {
				nx = tmp.x;
				ny = tmp.y;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N;
		init();
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < N; ++b) {
				cin >> game[a][b];
				if (game[a][b] >= 6 && game[a][b] <= 10) {
					if (wormhole.count(game[a][b])==1) {
						Node other_hole = wormhole[game[a][b]];
						wormhole[-game[a][b]] = other_hole;
						wormhole[game[a][b]] = { a,b };
					}
					else {
						wormhole[game[a][b]] = { a,b };
					}
				}
			}
		}
		int ans = 0;
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < N; ++b) {
				if (game[a][b] == 0) {
					for (int c = 0; c < 4; ++c) {
						ans = max(ans,go(a, b, c));
					}

				}
			}
		}
		cout << "#"<<t<<" " <<ans<<"\n";
	}


	return 0;
}
