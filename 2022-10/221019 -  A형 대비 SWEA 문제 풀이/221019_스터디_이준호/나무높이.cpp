#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans, maxi;
int cnt1, cnt2;
int tree[110];
vector<int> tong;

void init() {
	ans = 21e8;
	maxi = -21e8;
	cnt1 = 0;
	cnt2 = 0;
	for (int i = 0; i < 110; i++) {
		tree[i] = 0;
	}
	tong.clear();
}
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		maxi = max(maxi, tree[i]);
	}
}

void getCnt21(int tar) {
	cnt1 += tar % 2;
	cnt2 += tar / 2;
}

void solve() {
	for (int i = 0; i < n; i++) {
		tong.push_back(maxi - tree[i]);
		getCnt21(tong[i]);
	}
	if (cnt1 == 0 && cnt2 == 0) {
		ans = 0;
		return;
	}

	while (1) {
		//max함수 안의 값은 자리수
		int temp = max(2 * cnt2, 2 * cnt1 - 1);
		cnt2 -= 1;
		cnt1 += 2;

		if (ans != 21e8 && ans < temp) break;
		ans = min(ans, temp);
	}
}

int main()
{
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