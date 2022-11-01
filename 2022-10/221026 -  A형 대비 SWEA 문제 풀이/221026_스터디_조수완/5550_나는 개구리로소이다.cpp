#include <iostream>
#include <string>
using namespace std;
string tar; int result;

int check() {
	int cnt = 0;
	int used[3000] = { 0 };
	int c = 0, r = 0, o = 0, a = 0, k = 0;
	result = 0;

	for (int i = 0; i < tar.length(); i++) {
		if (used[i] == 1 && tar[i] == 'k') cnt--;
		if (used[i] == 1) continue;
		if (tar[i] != 'c') return 1;
		c = i;
		r = tar.find('r', r + 1);
		o = tar.find('o', o + 1);
		a = tar.find('a', a + 1);
		k = tar.find('k', k + 1);
		if (c == -1 || r == -1 || o == -1 || a == -1 || k == -1) return 1;
		if (c > r || c > o || c > a || c > k) return 1;
		if (r < c || r > o || r > a || r > k) return 1;
		if (o < c || o < r || o > a || o > k) return 1;
		if (a < c || a < r || a < o || a > k) return 1;
		if (k < c || k < r || k < o || k < a) return 1;
		used[c] = 1; used[r] = 1; used[o] = 1; used[a] = 1; used[k] = 1;
		cnt++;
		if (cnt > result) result = cnt;
	}
	return 0;
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		result = 0;
		cin >> tar;
		int flag = check();
		if (flag) result = -1;
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