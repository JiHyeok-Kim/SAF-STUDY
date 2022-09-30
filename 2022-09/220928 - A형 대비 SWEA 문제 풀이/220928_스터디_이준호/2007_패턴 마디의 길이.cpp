#include <iostream>
#include <string>
using namespace std;

string input;

bool solve(int len) {
	string first = "";
	for (int i = 0; i < len; i++) {
		first += input[i];
	}

	string second = "";
	for (int i = len; i < len * 2; i++) {
		second += input[i];
	}
	if (first == second) return 1;
	else return 0;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	
	for (int tc = 1; tc <= tcCnt; tc++) {
		cin >> input;

		int ans = 0;
		for (int len = 1; len <= 10; len++) {
			if (solve(len)) {
				ans = len;
				break;
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}