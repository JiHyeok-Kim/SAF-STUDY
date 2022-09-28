#include <iostream>
#include <string>
using namespace std;
string str;
int answer;

bool getPattern(int len) {
	string temp = "";
	for (int i = 0; i < len; i++) {
		temp += str[i];
	}
	string next = "";
	for (int i = len; i < len * 2; i++) {
		next += str[i];
	}

	if (temp == next) return true;
	else return false;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> str;
		answer = 0;

		for (int len = 1; len <= 10; len++) {
			if (getPattern(len)) {
				answer = len;
				break;
			}
		}

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}