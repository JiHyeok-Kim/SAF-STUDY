#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
vector<int> v;

void Solve(int tc) {
	sort(v.begin(), v.end());
	int dist = v[0];
	int cnt = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (dist == v[i]) {
			cnt++;
			continue;
		}
		break;
	}

	cout << "#" << tc << " " << dist << " " << cnt << "\n";
}

void init() {
	v.clear();
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		init();
		for (int i = 0; i < N; ++i) {
			int a;
			cin >> a;
			v.push_back(abs(a));
		}

		Solve(tc);
	}
	return 0;
}