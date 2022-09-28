#include <iostream>
#include <string>
using namespace std;
string str;
string tar;
void findTar() {
	int idx = 0;
	while (1) {
		tar += str[idx];
		int ret = str.find(tar, 1);
		if (tar.length() == ret) return;
		if (ret == -1) break;
		idx++;
	}
	return;
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		tar = "";
		cin >> str;
		int result = 0;
		int ret = 0;
		findTar();
		result = tar.length();
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