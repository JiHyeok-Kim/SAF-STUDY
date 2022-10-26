#include <iostream>
using namespace std;
int N, M, K, H;
long long map[1100][1100];
long long hap[1100][1100];

void input() {
	cin >> N >> M >> K >> H;
	for (int y = 1; y <= N; y++)for (int x = 1; x <= M; x++) cin >> map[y][x];
}
void solve() {
	input();
	for (int i = 0; i < K; i++) {
		int t, r1, c1, r2, c2, h;
		cin >> t >> r1 >> c1 >> r2 >> c2 >> h;
		if (t == 1) for (int y = r1 + 1; y <= r2 + 1; y++) { hap[y][c1 + 1] += h; hap[y][c2 + 2] -= h; }
		if (t == 0) for (int y = r1 + 1; y <= r2 + 1; y++) { hap[y][c1 + 1] -= h; hap[y][c2 + 2] += h; }
	}
	int result = 0;
	for (int y = 1; y <= N; y++)for (int x = 1; x <= M; x++) {
		hap[y][x] += hap[y][x - 1];
		map[y][x] += hap[y][x];
		if (map[y][x] > H) result++;
	}
	cout << result << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}