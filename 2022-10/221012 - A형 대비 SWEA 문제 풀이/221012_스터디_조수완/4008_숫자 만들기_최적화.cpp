#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, N, arr[15], oper[4];
int ans, path[15];
int maxi, mini;

void init() {
	maxi = -21e8, mini = 21e8;
}

int calc(int a, int b, int oper) {
	if (oper == 0) return a + b;
	if (oper == 1) return a - b;
	if (oper == 2) return a * b;
	if (oper == 3) return a / b;
}

void sol(int lev,int sum) {
	if (lev == N-1) {
		maxi = max(sum, maxi);
		mini = min(sum, mini);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] == 0)continue;
		oper[i]--;
		sol(lev + 1, calc(sum, arr[lev + 1], i));
		oper[i]++;
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		init();
		for (int i = 0; i < 4; i++) cin >> oper[i];
		for (int i = 0; i < N; i++) cin >> arr[i];
		sol(0, arr[0]);
		ans = maxi - mini;
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}