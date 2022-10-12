#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
	int lv;
};

int N, M, hM, maxi;
int map[20][20];
int directY[4] = { -1,1,0,0 };
int directX[4] = { 0,0,-1,1 };

void init()
{
	hM = 0;
	maxi = 0;
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) hM++;
		}
	}

	return;
}

int BangBum(int ty, int tx, int k)
{
	int cost = k * k + (k - 1) * (k - 1);
	int house = 0;
	int visit[20][20] = { 0 };
	if (cost > hM * M) return -1;

	queue<Node> q;
	q.push({ ty, tx, 1 });
	if (map[ty][tx] == 1) house++;
	visit[ty][tx] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visit[ny][nx] == 1) continue;
			if (now.lv == k) continue;
			if (map[ny][nx] == 1) house++;
			visit[ny][nx] = 1;
			q.push({ ny, nx, now.lv + 1 });
		}
	}

	if (house * M < cost) return -1;

	return house;
}

void goService(int ty, int tx)
{
	for (int i = 1; i <= N + 1; i++) {
		int num = BangBum(ty, tx, i);
		if (maxi == hM) return;
		if (num > maxi) maxi = num;
	}

	return;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		init();

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (maxi == hM) break;
				goService(y, x);
			}
			if (maxi == hM) break;
		}

		cout << "#" << tc << " " << maxi << "\n";
	}


	return 0;
}