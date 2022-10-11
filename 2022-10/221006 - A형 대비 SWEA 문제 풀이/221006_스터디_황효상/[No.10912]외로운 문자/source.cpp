#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;
int T;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

//	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string tmp;
		cin >> tmp;
		sort(tmp.begin(), tmp.end());
		tmp += "A";
		string ans = "";
		for (int a = 0; a < tmp.size() - 1; ++a) {
			if (tmp[a] == tmp[a + 1])
				++a;
			else {
				ans += tmp[a];
			}
		}
		cout << "#" << t << " ";
		if (ans == "")
			cout << "Good\n";
		else
			cout << ans << "\n";
	}
}
