#include <iostream>
#include <string>
using namespace std;
int T;
string f, s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> f >> s;
		int fs = (f[6] - '0') * 10 + (f[7] - '0');
		int ss = (s[6] - '0') * 10 + (s[7] - '0');
		int fm = (f[3] - '0') * 10 + (f[4] - '0');
		int sm = (s[3] - '0') * 10 + (s[4] - '0');
		int fh = (f[0] - '0') * 10 + (f[1] - '0');
		int sh = (s[0] - '0') * 10 + (s[1] - '0');
		int rm = 0, rh = 0;
		int rs = (ss - fs >= 0 ? ss - fs : (60 + ss - fs));
		if (ss - fs < 0)rm--;
		rm += (sm - fm >= 0 ? sm - fm : (60 + sm - fm));
		if (sm - fm < 0)rh--;
		rh += (sh - fh >= 0 ? sh - fh : 24 + sh - fh);
		if (rh == -1) rh = 23;
		cout << "#" << t << " ";
		if (rh < 10)cout << "0" << rh << ":";
		else cout << rh << ":";
		if (rm < 10)cout << "0" << rm << ":";
		else cout << rm << ":";
		if (rs < 10)cout << "0" << rs << "\n";
		else cout << rs << "\n";
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