#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[10];
int path[3];
int used[7];
int ans;

vector<int> sumTong;

void init() {
	ans = 0;
	for (int i = 0; i < 10; i++) {
		map[i] = 0;
	}
	sumTong.clear();
}

void dfs(int lev, int start) {
	if (lev == 3) {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += path[i];
		}
		sumTong.push_back(sum);
		return;
	}

	for (int i = start; i < 7; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = map[i];
		dfs(lev + 1, i);
		path[lev] = 0;
		used[i] = 0;
	}
}


void solve() {
	sort(map, map + 10, greater<int>());

	dfs(0, 0);
	sort(sumTong.begin(), sumTong.end(), greater<int>());
	int idx = 0;
	for (int i = 0; i < sumTong.size() - 1; i++) {
		if (sumTong[i] != sumTong[i + 1]) {
			idx++;
		}
		if (idx == 4) {
			ans = sumTong[i + 1];
			break;
		}
	}

}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		for (int i = 0; i < 7; i++) {
			cin >> map[i];
		}
		solve();
		
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}