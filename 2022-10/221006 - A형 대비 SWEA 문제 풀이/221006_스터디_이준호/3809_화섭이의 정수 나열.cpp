#include <iostream>
#include <string>
using namespace std;

int n, ans;
char ch;
string num;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		num += ch;
	}
}

void solve() {
	int idx = 0;
	while (1) {
		string tar = to_string(idx);
		if (num.find(tar) == -1) break;
		idx++;
	}
	ans = idx;
}

int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		ans = 0;
		num = "";
		input();
		solve();

		cout << "#" << tc << " " << ans << "\n";
	}


	return 0;
}