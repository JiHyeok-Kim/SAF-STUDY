#include <iostream>
#include <cstring>
using namespace std;

int n, ans;
string tar;

void solve() {
	int dat[150] = {0};
	for (int i = 0; i < n; i++) {
		dat[tar[i]]++;
	}
	int flag = 0;
	if (dat['<'] != dat['>'] || dat['('] != dat[')'] ||
		dat['['] != dat[']'] || dat['{'] != dat['}']) flag = 1;
	if (flag == 1) ans = 0;
	else ans = 1;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		cin >> n >> tar;
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}