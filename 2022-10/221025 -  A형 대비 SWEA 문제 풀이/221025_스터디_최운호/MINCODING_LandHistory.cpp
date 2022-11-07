#include <iostream>
using namespace std;

int map[1000][1000];
int sum[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = 0;

	int N, M, K, H;
	cin >> N >> M >> K >> H;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int t, r1, c1, r2, c2, h;
		cin >> t >> r1 >> c1 >> r2 >> c2 >> h;
		if (t == 0) h = -h;
		for (int i = r1; i <= r2; i++) {
			sum[i][c1] += h;
			sum[i][c2 + 1] += -h;
		}
	}

	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 0; j < M; j++) {
			tmp += sum[i][j];
			map[i][j] += tmp;
			if (map[i][j] > H) answer++;
		}
	}

	cout << answer;

	return 0;
}