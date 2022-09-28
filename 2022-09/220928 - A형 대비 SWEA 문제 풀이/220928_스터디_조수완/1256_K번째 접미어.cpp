#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int T, N;
string str;
string tar[450];

void setTar() {
	for (int i = 0; i < str.length(); i++) {
		tar[i] = &str[str.length() - 1 - i];
	}
	sort(tar, tar+(str.length()));
}
void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cin >> str;
		setTar();
		cout << "#" << t << " " << tar[N - 1] << "\n";
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