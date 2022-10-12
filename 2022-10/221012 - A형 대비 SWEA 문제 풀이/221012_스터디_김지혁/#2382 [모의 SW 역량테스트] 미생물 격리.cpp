#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	int num;
	int dt;
	int cmp;
};

int N, M, K;
Node map[100][100];
Node temp[100][100];
int directY[5] = { 0,-1,1,0,0 }; // »óÇÏÁÂ¿ì
int directX[5] = { 0,0,0,-1,1 };

void init()
{
	memset(map, 0, sizeof(map));
	memset(temp, 0, sizeof(temp));
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		cin >> map[y][x].num >> map[y][x].dt;
	}

	return;
}

int ans() {
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x].num == 0) continue;
			cnt += map[y][x].num;
		}
	}

	return cnt;
}

int run()
{
	for (int t = 0; t < M; t++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x].num == 0) continue;
				int dy = y + directY[map[y][x].dt];
				int dx = x + directX[map[y][x].dt];
				if (dy == 0 || dx == 0 || dy >= N - 1 || dx >= N - 1) {
					map[y][x].num /= 2;
					temp[dy][dx] = map[y][x];
					if (temp[dy][dx].dt == 1) temp[dy][dx].dt = 2;
					else if (temp[dy][dx].dt == 2) temp[dy][dx].dt = 1;
					else if (temp[dy][dx].dt == 3) temp[dy][dx].dt = 4;
					else if (temp[dy][dx].dt == 4) temp[dy][dx].dt = 3;
				}
				else if (temp[dy][dx].num == 0) {
					temp[dy][dx] = map[y][x];
					temp[dy][dx].cmp = map[y][x].num;
				}
				else {
					if (temp[dy][dx].cmp < map[y][x].num) {
						temp[dy][dx].cmp = map[y][x].num;
						temp[dy][dx].dt = map[y][x].dt;
					}
					temp[dy][dx].num += map[y][x].num;
				}
				map[y][x].num = 0;
				map[y][x].dt = 0;
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (temp[y][x].num == 0) continue;
				map[y][x] = temp[y][x];
				temp[y][x].num = 0;
				temp[y][x].dt = 0;
				temp[y][x].cmp = 0;
			}
		}
	}

	return ans();
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		cout << "#" << tc << " " << run() << "\n";
	}

	return 0;
}