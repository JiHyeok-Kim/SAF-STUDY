#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, N, arr[15], oper[4];
int ans, used[15], path[15];
int maxi, mini;
vector<int> oper1;

void init() {
	ans = 0, maxi = -21e8, mini = 21e8;
	for (int i = 0; i < 15; i++) used[i] = 0;
	oper1.clear();
}

int calc(int a, int b, int oper) {
	if (oper == 0) return a + b;
	if (oper == 1) return a - b;
	if (oper == 2) return a * b;
	if (oper == 3) return a / b;
}

void sol(int lev,int calcLev,int start) {
	if (lev == oper[calcLev] && calcLev==3) {
		int temp = calc(arr[0], arr[1], path[0]);
		for (int i = 2; i < N; i++) {
			temp = calc(temp, arr[i], path[i-1]);
		}
		maxi = max(temp, maxi);
		mini = min(temp, mini);
		return;
	}
	if (lev == oper[calcLev]) {
		sol(0, calcLev + 1,0);
		return;
	}
	for (int i = start; i < N - 1; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[i] = calcLev;
		sol(lev + 1, calcLev, i + 1);
		used[i] = 0;
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		init();
		for (int i = 0; i < 4; i++) {
			cin >> oper[i];
		}
		for (int i = 0; i < N; i++) cin >> arr[i];
		sol(0, 0, 0);
		ans = maxi - mini;
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}