#include <iostream>
using namespace std;

int N, M;
int map[1001][1001];
int sum[1001][1001];

int main()
{
	cin >> N >> M;
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= N; ++x) {
			cin >> map[y][x];
		}
	}

	for (int y = 1; y <= N; ++y) {
		sum[y][1] = map[y][1];
		for (int x = 2; x <= N; ++x) {
			sum[y][x] = sum[y][x - 1] + map[y][x];
		}
	}

	for (int i = 0; i < M; ++i) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		int ret = 0;
		for (int y = y1; y <= y2; ++y) {
			ret += (sum[y][x2] - sum[y][x1 - 1]);
		}
		cout << ret << "\n";
	}

	return 0;
}