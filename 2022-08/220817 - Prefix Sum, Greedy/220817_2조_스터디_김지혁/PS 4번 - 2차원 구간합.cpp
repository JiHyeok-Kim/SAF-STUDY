#include <iostream>
using namespace std;

int arr[1000][1000];
int arrSum[1001][1001];
int directY[3] = { -1, 0 , -1 };
int directX[3] = { 0, -1 , -1 };

void sumArr(int y, int x)
{
	for (int i = 0; i < 3; i++)
	{
		int dy = y + directY[i];
		int dx = x + directX[i];
		if (i == 2) { arrSum[y][x] -= arrSum[dy][dx]; continue; }
		arrSum[y][x] += arrSum[dy][dx];
	}

	return;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			sumArr(y, x);
			arrSum[y][x] += arr[y - 1][x - 1];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int sum = arrSum[y2][x2] - arrSum[y1 - 1][x2] - arrSum[y2][x1 - 1] + arrSum[y1 - 1][x1 - 1];
		cout << sum << "\n";
	}

	return 0;
}