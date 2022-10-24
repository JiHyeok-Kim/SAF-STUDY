#include <iostream>
using namespace std;

int n, ans, sum;
int wei[9];
int used[9];
int EXP[10] = { 1,2,4,8,16,32,64,128,256,512 };
int FACT[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };

void init() {
	ans = 0;
	sum = 0;
	for (int i = 0; i < 9; i++) {
		wei[i] = 0;
		used[i] = 0;
	}
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wei[i];
		sum += wei[i];
	}
}

void dfs(int lev, int L, int R) {
	if (lev == n) {
		ans++;
		return;
	}
	if (L > sum / 2) {
		ans += EXP[n - lev] * FACT[n - lev];
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		dfs(lev + 1, L + wei[i], R);
		if (L >= R + wei[i]) dfs(lev + 1, L, R + wei[i]);
		used[i] = 0;
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
		dfs(0, 0, 0);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}