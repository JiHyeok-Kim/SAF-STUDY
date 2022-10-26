#include <iostream>
using namespace std;

int N, M, K, H, ans;
int map[1010][1010];
int tempMap[1010][1010];
int t, r1, c1, r2, c2, num;

void solve() {
	for (int y = r1; y <= r2; y++) {
		if (t == 1) {
			tempMap[y][c1] += num;
			tempMap[y][c2 + 1] -= num;
		}
		else {
			tempMap[y][c1] -= num;
			tempMap[y][c2 + 1] += num;
		}
	}
}

void input() {
	cin >> N >> M >> K >> H;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	// �־��� ���� ù ���� ����, �������� �������� �ݴ� ����
	for (int i = 0; i < K; i++) {
		cin >> t >> r1 >> c1 >> r2 >> c2 >> num;
		solve();
	}
	// 1���� prefixSuM
	for (int y = 0; y < N; y++) {
		for (int x = 1; x < M; x++) {
			tempMap[y][x] += tempMap[y][x - 1];
		}
	}
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] + tempMap[y][x] > H) ans++;
		}
	}
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	cout << ans;
	return 0;
}