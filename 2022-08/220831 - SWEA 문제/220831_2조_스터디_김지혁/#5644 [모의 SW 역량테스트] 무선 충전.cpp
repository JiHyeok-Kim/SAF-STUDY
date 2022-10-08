#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Map {
	int api;
	int arr[8];
};

struct Node {
	int y;
	int x;
	int lev;
};

int M, N, maxi;
Map map[11][11];
vector<int> A;
vector<int> B;
int directY[5] = { 0, -1, 0, 1, 0 };
int directX[5] = { 0, 0, 1, 0, -1 };

void goApi(int idx, int tx, int ty, int C, int P)
{
	queue<Node> q;
	q.push({ ty, tx, 0 });

	map[ty][tx].api = 1;
	map[ty][tx].arr[idx] = P;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 1; i < 5; i++)
		{
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];
			if (now.lev == C) continue;
			if (ny < 1 || nx < 1 || ny >= 11 || nx >= 11) continue;
			map[ny][nx].api = 1;
			map[ny][nx].arr[idx] = P;
			q.push({ ny, nx, now.lev + 1 });
		}
	}

	return;
}

void init()
{
	//ÃÊ±âÈ­
	maxi = 0;
	A.clear();
	B.clear();
	memset(map, 0, sizeof(map));

	cin >> M >> N;
	A.push_back(0);
	B.push_back(0);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;
			if (i == 0) A.push_back(n);
			else B.push_back(n);
		}
	}

	for (int i = 0; i < N; i++) {
		int x, y, C, P;
		cin >> x >> y >> C >> P;
		goApi(i, x, y, C, P);
	}

	return;
}

int goPower(int Ay, int Ax, int By, int Bx)
{
	int power = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int temp;
			if (y == x) {
				temp = max(map[Ay][Ax].arr[y], map[By][Bx].arr[x]);
			}
			else {
				temp = map[Ay][Ax].arr[y] + map[By][Bx].arr[x];
			}
			if (temp > power) power = temp;
		}
	}

	return power;
}

void moveAB()
{
	int Ay = 1, Ax = 1;
	int By = 10, Bx = 10;

	for (int i = 0; i <= M; i++) {
		Ay += directY[A[i]];
		Ax += directX[A[i]];
		By += directY[B[i]];
		Bx += directX[B[i]];

		maxi += goPower(Ay, Ax, By, Bx);
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		moveAB();
		cout << "#" << tc << " " << maxi << "\n";
	}

	return 0;
}