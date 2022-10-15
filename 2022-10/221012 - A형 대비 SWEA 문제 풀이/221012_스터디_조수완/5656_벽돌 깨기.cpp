#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int y, x;
};

int T, N, W, H, maxi;
int temp[20][20], used[20][20];
int map[20][20];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };

int getCnt(int ty, int tx) {
	queue<Node> q;
	int used[20][20] = { 0 };
	int cnt = 1;
	used[ty][tx] = 1;
	q.push({ ty,tx });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		int num = temp[now.y][now.x];
		temp[now.y][now.x] = 0;

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < 4; j++) {
				int ny = now.y + (drY[j] * i);
				int nx = now.x + (drX[j] * i);
				if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
				if (used[ny][nx] == 1) continue;
				if (temp[ny][nx] == 0)continue;
				used[ny][nx] = 1;
				q.push({ ny,nx });
				cnt++;
			}
		}
	}
	return cnt;
}

void setMap() {
	for (int x = 0; x < W; x++) {
		for (int y = H - 1; y >= 0; y--) {
			if (temp[y][x] != 0) {
				for (int t = y; t < H - 1; t++) {
					if (temp[t + 1][x] != 0) break;
					swap(temp[t][x], temp[t + 1][x]);
				}
			}
		}
	}
}
int xPath[5], usedx[20];
void getPath(int lev) {
	if (lev == N) {
		for (int yy = 0; yy < H; yy++) {
			for (int xx = 0; xx < W; xx++) {
				temp[yy][xx] = map[yy][xx];
			}
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int y = 0; y < H; y++) {
				if (temp[y][xPath[i]] == 0) continue;
				int cnt = getCnt(y, xPath[i]);
				sum += cnt;
				setMap();
				if (y == 2 && xPath[0] == 2 && xPath[1] == 2) {
					int a = 0;
				}
				break;
			}
		}
		maxi = max(maxi, sum);
		return;
	}
	for (int x = 0; x < W; x++) {
		xPath[lev] = x;
		getPath(lev + 1);
		xPath[lev] = NULL;
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> W >> H;
		int total = 0;
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				cin >> map[y][x];
				if (map[y][x] != 0) total++;
			}
		}
		maxi = -1;
		getPath(0);
		cout << "#" << t << " " << total - maxi << '\n';
	}
	return 0;
}