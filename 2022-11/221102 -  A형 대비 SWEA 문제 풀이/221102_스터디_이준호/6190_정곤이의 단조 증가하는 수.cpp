#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans, gop;
int map[1001];
vector<int> v;


void init() {
	memset(map, 0, sizeof(map));
	v.clear();
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
}

bool isDanjo(int num) {
	string tar = to_string(num);

	for (int i = 0; i < tar.size() - 1; i++) {
		if (tar[i] > tar[i + 1]) return false;
	}
	return true;
}


void solve() {
	for (int i = 0; i < N - 1; i++) {
		if (map[i] % 10 == 0) continue;

		for (int j = i + 1; j < N; j++) {
			if (map[j] % 10 == 0) continue;
			int temp = map[i] * map[j];
			if (isDanjo(temp)) v.push_back(temp);
		}
	}
	if (v.size() == 0) {
		ans = -1;
		return;
	}
	sort(v.begin(), v.end(), greater<int>());
	ans = v[0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}