#include <iostream>
#include <algorithm>
using namespace std;

int N;
int box[100];
int answer = 0;

void init() {
	cin >> N;
	answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> box[i];
	}

	sort(box, box + N, greater<int>());
}

void solve() {
	int s = 0;
	int e = N - 1;
	while (s <= e) {
		int w = box[s];
		if (w >= 50) {
			answer++;
			s++;
			continue;
		}

		int idx = 0;
		for (int i = 1; i <= e - s; i++) {
			if (w * (i + 1) >= 50) {
				idx = i;
				break;
			}
		}

		if (idx == 0) return;

		s++;
		e -= idx;
		answer++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();

		solve();

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}