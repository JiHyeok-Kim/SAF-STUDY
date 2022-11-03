#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
string name[20010];

bool cmp(string t, string v) {
	if (t.length() != v.length()) return t.length() < v.length();
	return t < v;
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> name[i];
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		sort(name, name + N, cmp);
		cout << "#" << t << "\n";
		string xstr = name[0];
		cout << name[0] << "\n";
		for (int i = 1; i < N; i++) {
			if (xstr == name[i]) continue;
			cout << name[i] << "\n";
			xstr = name[i];
		}
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