#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int dat[26];
string str;
string ans;

void init() {
	for (int i = 0; i < 26; i++) {
		dat[i] = 0;
	}
	ans = "";
}

void solve() {
	for (int k = 0; k < str.length(); k++) {
		char tar = str[k] - 'a';
		dat[tar]++;
	}
	
	for (int i = 0; i < 26; i++) {
		if (dat[i] % 2 == 1) {
			ans += char(i + 'a');
		}
	}

	if (ans == "") {
		ans = "Good";
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		cin >> str;

		solve();

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}