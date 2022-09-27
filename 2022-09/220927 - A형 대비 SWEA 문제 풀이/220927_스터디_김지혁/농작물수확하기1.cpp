#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node
{
	int y;
	int x;
	int lv;
};

int N;
int map[50][50];
int bucket[50][50];
int directY[4] = { 1,-1,0,0 };
int directX[4] = { 0,0,-1,1 };

int floodfill(int ty, int tx)
{
	int ans = 0;

	int n = (N - 1) / 2;
	queue<Node> q;
	q.push({ ty, tx, 0 });
	bucket[ty][tx] = map[ty][tx];
	ans += bucket[ty][tx];

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (bucket[ny][nx] != 0) continue;
			if (now.lv == n) continue;
			bucket[ny][nx] = map[ny][nx];
			ans += bucket[ny][nx];
			q.push({ ny, nx, now.lv + 1 });
		}
	}

	return ans;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio;

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		memset(map, 0, sizeof(map));
		memset(bucket, 0, sizeof(bucket));
		for (int y = 0; y < N; y++)
		{
			string str;
			int idx = -1;
			cin >> str;
			for (int x = 0; x < N; x++)
			{
				idx++;
				map[y][x] = str[idx] - '0';
			}
		}
		int n = (N - 1) / 2;
		int ans = floodfill(n, n);
		
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}
