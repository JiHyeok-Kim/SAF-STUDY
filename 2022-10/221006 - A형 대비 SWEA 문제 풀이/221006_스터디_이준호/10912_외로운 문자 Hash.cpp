#include <iostream>
#include <unordered_map>
using namespace std;

string str;
string ans;
unordered_map<char, int> um;

void init() {
	ans = "";
	um.clear();
}

void solve() {
	for (int k = 0; k < str.size(); k++) {
		um[str[k]]++;
	}

	for (char ch = 'a'; ch <= 'z'; ch++) {
		if (um.count(ch) == 1) {
			if (um[ch] % 2 == 1) {
				ans += ch;
			}
		}
	}

	if (ans == "") ans = "Good";
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