#include <iostream>
using namespace std;
int arr[19], ans1, ans2;
int path[9];
int num[9] = { 362880,40320,5040,720,120,24,6,2,1 };
void init() {
	for (int i = 1; i < 19; i++) arr[i] = 0;
	ans1 = 0;
	ans2 = 0;
}
void input() {
	for (int i = 0; i < 9; i++) {
		cin >> path[i];
		arr[path[i]] = 1;
	}
}
void solution(int lev, int sum1, int sum2) {
	if (lev == 9) {
		if (sum1 >= sum2) ans1++;
		if (sum1 <= sum2) ans2++;
		return;
	}
	if (sum1 > 86) {
		ans1 +=num[lev];
		return;
	}
	if (sum2 > 86) {
		ans2 += num[lev];
		return;
	}
	for (int b = 1; b < 19; b++) {
		if (arr[b] == 1) continue;
		arr[b] = 1;
		if (path[lev] > b) solution(lev + 1, sum1 + path[lev] + b, sum2);
		else solution(lev + 1, sum1, sum2 + path[lev] + b);
		arr[b] = 0;
	}
}

void solve() {
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		init();
		input();
		solution(0, 0, 0);
		cout << "#" << t << " " << ans1 << " " << ans2 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}