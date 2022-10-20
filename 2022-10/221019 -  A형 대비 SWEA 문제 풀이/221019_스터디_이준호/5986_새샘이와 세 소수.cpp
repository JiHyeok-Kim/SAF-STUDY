#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

vector<int> tong;
int n, ans, last;
int path[3];

bool isSosu(int num) {
	int last = sqrt(num);
	for (int i = 2; i <= last; i++) {
		if (num % i == 0) return 0;
	}
	return 1;
}
void makeTong() {
	for (int i = 2; i <= 999; i++) {
		if (isSosu(i)) {
			tong.push_back(i);
		}
	}

}

void findlast() {
	if (n > 997) {
		last = 167;
		return;
	}
	for (int i = 0; i < tong.size(); i++) {
		if (tong[i] >= n) {
			last = i - 1;
			break;
		}
	}
}

void dfs(int lev, int sum, int start) {
	if (lev == 3) {
		if (sum == n) ans++;
		return;
	}

	if (sum >= n) return;

	for (int i = start; i >= 0; i--) {
		dfs(lev + 1, sum + tong[i], i);
	}

}


int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	makeTong();
	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> n;
		ans = 0;
		findlast();
		dfs(0, 0, last);
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}