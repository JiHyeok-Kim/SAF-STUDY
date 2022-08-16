#include <iostream>
using namespace std;

int T, N, W;
int map[100000];

void slidingWindow() {
	int start = 0;
	for (int i = 0; i < W; ++i) {
		start += map[i];
	}

	int ret_max = start;
	int ret_idx = 0;
	for (int i = 0; i <= N - W; ++i) {
		if (i == N - W) break;
		start += map[i + W];
		start -= map[i];

		if (ret_max < start) {
			ret_max = start;
			ret_idx = i + 1;
		}
	}

	cout << ret_idx << " " << ret_idx + W - 1 << " " << ret_max << "\n";
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> W;
		for (int i = 0; i < N; ++i) {
			cin >> map[i];
		}

		cout << "#" << tc << " ";
		slidingWindow();
	}
	return 0;
}