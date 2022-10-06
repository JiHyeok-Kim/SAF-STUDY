#include <iostream>
using namespace std;
int nums[7], result, rank1[7];

void getRank(int num) {
	for (int i = 0; i < 5; i++) if (num == rank1[i]) return;
	for (int i = 0; i < 5; i++) {
		if (num > rank1[i]) {
			if (i == 0) {
				rank1[0] = num;
			}
			else {
				int temp = rank1[i];
				rank1[i] = rank1[i - 1];
				rank1[i - 1] = temp;
			}
		}
		else break;
	}
}
void dfs(int lev,int sum,int start) {
	if (lev == 3) {
		getRank(sum);
		return;
	}

	for (int i = start; i < 7; i++) {
		dfs(lev + 1, sum + nums[i], i + 1);
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 7; i++) {
			cin >> nums[i];
			rank1[i] = 0;
		}
		dfs(0,0,0);
		result = rank1[0];
		cout << "#" << t << " " << result << "\n";
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