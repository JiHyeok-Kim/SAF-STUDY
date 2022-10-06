#include <iostream>
#include <string>
using namespace std;
string str;
int arr[30];
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 30; i++) arr[i] = 0;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			arr[str[i] - 'a']++;
		}
		cout << "#" << t << " ";
		int flag = 1;
		for (int i = 0; i <= 'z'-'a'; i++) {
			if (arr[i] % 2 == 1) {
				cout << (char) (i + 'a');
				flag = 0;
			}
		}
		if (flag) cout << "Good\n";
		else cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}