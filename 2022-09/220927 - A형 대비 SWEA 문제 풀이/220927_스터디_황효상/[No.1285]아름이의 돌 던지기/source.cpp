#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int stone[1001];
int N;
void input() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		memset(stone, 0, sizeof(stone));
		for (int a = 0; a < N; ++a) {
			cin >> stone[a];
			if (stone[a] < 0) {
				stone[a] = -stone[a];
			}
		}
		sort(stone, stone + N);
		int cnt = N;
		for (int a = 1; a < N; ++a) {
			if (stone[0] != stone[a]) {
				cnt = a;
				break;
			}
		}
		cout << "#" << t << " " << stone[0] << " " << cnt << "\n";
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	input();
	return 0;
}
